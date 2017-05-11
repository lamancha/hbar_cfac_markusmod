#!/bin/bash

CFAC_TAR="cfac-1.4.1.tar.gz";
CFAC_TAR_DIR="cfac"
CFAC_DIRNAME="cfac-1.4.1"
CAN_INSTALL=1
NOWPATH=$(pwd)
FACDIR="./"
RETURNCODE=0


function Main()
{
	CheckRequirements
	PrintInitialInstructions
	if [ $REPLY -eq 1 ]
	then
		PromptAndInstallCfac
		UpdateCfacReferences
	elif [ $REPLY -eq 2 ]
	then
		PurgeCfacReferences
	elif [ $REPLY -eq 4 ]
	then
	   UpdateCfacReferences
	fi
	PromptAndConfigureHbarGshfs
	FinalizeSetup
}


function CheckRequirements()
{
	#Check if we have a makefile in the current directory. If not, we are obviously not in the project directory.
	if [ ! -f "makefile.in" ]
	then
		echo "Fatal error: This script must be run from the base directory of the project."
		RETURNCODE=1
		exit $RETURNCODE
	fi
	#Check if the cfac file is present. If not, we obviously cannot install it.
	if [ ! -f $CFAC_TAR_DIR/$CFAC_TAR ]
	then
		echo "Could not find the file $CFAC_TAR_DIR/$CFAC_TAR. This script will not be able to install it for you."
		RETURNCODE=2
		CAN_INSTALL=0
	fi
}

function PrintInitialInstructions()
{
	echo "This is a simple setup script to help you configuring the project for your purposes."
	echo -e "There are some common configurations: \n"
	echo "(1) Full configuration (including cfac):"
	echo -e "\t Use this if you need to generate decay data using SFAC."
	echo -e "\t In order to use this setup, you need to setup and install cfac-1.4.1 first."
	if [ $CAN_INSTALL -eq 1 ]
	then
		echo -e "\t This setup script can help you do that."
	else
		echo -e "\t This script CANNOT help you with that since the file $CFAC_TAR_DIR/$CFAC_TAR is missing."
	fi
	echo "(2) Limited configuration (not including cfac):"
	echo -e "\t Use this if you do NOT need to generate decay data using SFAC."
	echo -e "\t This configuration will disable the compilation of the binary generation program, as well as the stage 1 root processing program for the binary data files."
	echo "(3) Very limited configuration (only hbar_gshfs autoconfig):"
	echo -e "\t Use this if everything is already set up, except for the hbar_gshfs reference to this directory.\n"
	echo -e "Word of warning: this script will touch files at locations you point it to. Use with care. There is no warranty.\n"
	read -p "Choose your desired option. (1/2/3)" -n 1 -r
	while [ $REPLY -ne 1 ] && [ $REPLY -ne 2 ] && [ $REPLY -ne 3 ] && [ $REPLY -ne 4 ]
	do
		echo -en "\n"
		read -p "Please select 1, 2 or 3." -n 1 -r 
	done
	echo -en "\n"
}

function PromptAndInstallCfac()
{
	echo "Make sure you have installed a valid fortran77 compiler (?maybe not gfortran?) before proceeding."
	read -p "Enter the directory to unpack cfac-1.4.1:" FACDIR
	cp $CFAC_TAR_DIR/$CFAC_TAR $FACDIR
	cd $FACDIR
	tar -xzvf $CFAC_TAR
	if [ $? -ne 0 ]
	then
		echo "Tar returned nonzero exit code. Something went wrong."
		RETURNCODE=10
	fi
	cd $CFAC_DIRNAME
	if [ ! -f "configure" ]
	then
		echo "Could not find configuration file. Unpacking could not have been successful."
		RETURNCODE=11
	fi
	echo "You will now need to enter configuration parameters for the cfac-1.4.1 setup script."
	echo "The help file for cfac says:"
	./configure --help
    if [ $? -ne 0 ]
	then
		echo "Configure returned nonzero exit code. Something went wrong."
		RETURNCODE=20
	fi
	read -p "Enter the configuration options you would like to use:" OPT
	./configure $OPT
	while [ $? -ne 0 ]
	do
		echo "Configure returned nonzero exit code. Something went wrong. Please try to enter the arguments again."
		read -p "Enter the configuration options you would like to use:" OPT
		./configure $OPT
	done

	echo "Compiling..."
	make
	if [ $? -ne 0 ]
	then
		echo "Compilation failed!"
		RETURNCODE=30
	fi
	if [ $RETURNCODE -eq 0 ]
	then
		echo "Installing..."
		make install
		if [ $? -ne 0 ]
		then
			echo "Installation failed!"
			RETURNCODE=40
		fi
	else
		echo "Previous error, will not install."
	fi
	cd $NOWPATH
}

function PurgeCfacReferences()
{
	cp makefile.in makefile
	sed -i -e '/@FACDIRECTORY@/d' makefile
	sed -i -e '/FACINCLUDE:=/d' makefile
	sed -i -e '/FACLIB:=/d' makefile
	sed -i -e '/dbase.c/d' makefile
	sed -i -e '/dbase.h/d' makefile
	sed -i -e '/FACDEP_MAINS:=/d' makefile
	sed -i -e '/FACDEPEND:=/d' makefile
	sed -i -e "s,@FACEXCLUDE@,read rfacDB rfacEN bingen rfacENF rfacEssentialDataReader rfacF rfacTR rfacTRF rootgen,g" makefile
}

function PromptAndConfigureHbarGshfs()
{
	read -p "Auto-configure hbar_gshfs variables to point at this directory? (y/n)" -n 1 -r
	echo -en "\n"
	if [[ $REPLY =~ ^[yY]$ ]]
	then
		read -p "Enter the absolute path to the hbar_gshfs directory:" hbarDir
		while [ ! -f "$hbarDir/setup.sh" ]
		do
			read -p "The path seems incorrect, please try again:" hbarDir
		done
		if [ -f "$hbarDir/Makefile" ]
		then
			chmod a+w $hbarDir/Makefile
			sed -i -e "s,RFAC:=.*,RFAC:=$NOWPATH,g" $hbarDir/Makefile
			chmod a-w $hbarDir/Makefile
		else
			echo "Could not find hbar_gshfs makefile. Did you remember to run $hbarDir/setup.sh ?"
		fi
	fi
}

function FinalizeSetup()
{
	echo "Setup complete. If you experienced any problems, contact Rikard."
}

function UpdateCfacReferences()
{
	cd $NOWPATH
	if [ -z $FACDIR ]
	then
		read -p "Enter the absolute path to the parent of the cfac-1.4.1 directory:" FACDIR
	fi
	cp makefile.in makefile
	sed -i -e "s,@FACDIRECTORY@,$FACDIR/cfac-1.4.1,g" makefile
	sed -i -e "s,@FACEXCLUDE@,,g" makefile
	read -p "Auto-apply patch to cfac code? (y/n)" -n 1 -r
	echo -en "\n"
	if [[ $REPLY =~ ^[yY]$ ]]
	then
		cp patches/rfac.p2.diff $FACDIR/rfac.p2.diff
		cd $FACDIR
		patch -p1 < rfac.p2.diff
		cd $NOWPATH
		echo "Patch applied."
	fi
}

Main
