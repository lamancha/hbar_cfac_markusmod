#!/bin/bash
for i in $(ls decayWeb | grep -v '~')
do
    scp decayWeb/$i lundmark@smilx0.smi.oeaw.ac.at:/var/www/html/decay
done