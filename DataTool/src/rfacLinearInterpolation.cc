#include "rfacLinearInterpolation.hh"

ClassImp(rfacLinearInterpolation)


rfacLinearInterpolation::rfacLinearInterpolation(const vector<Double_t> &coordinates, const vector<Double_t> &values)
{
  if(coordinates.size() < 2)
    throw rfacException("Too few points.");

  if(coordinates.size() != values.size())
    {
      throw rfacException("Wrong number of coordinate points specificed.");
    }
  for(vector<Double_t>::const_iterator ix = coordinates.begin(), iy = values.begin(); ix != coordinates.end() && iy != values.end(); ix++, iy++)
    {
      dataPoints.push_back(make_pair(*ix,*iy));
    }
  sort(dataPoints.begin(), dataPoints.end());
}

rfacLinearInterpolation::rfacLinearInterpolation(const vector<pair<Double_t, Double_t> > &data)
{
  if(data.size() < 2)
    throw rfacException("Too few points.");
  dataPoints = data;
  sort(dataPoints.begin(), dataPoints.end());
  for(int i = 0; i<(int)dataPoints.size()-1; ++i)
    {


      if(dataPoints[i].first == dataPoints[i+1].first)
	{
	  cerr << "Input data:" << endl;
	  for(vector<pair<Double_t, Double_t> >::const_iterator it = data.begin(); it!=data.end(); ++it)
	    {
	      cerr << it->first << " " << it->second << endl;
	    }
	  throw rfacException("Function needs to be injective.");
	}
    }
}

rfacLinearInterpolation::rfacLinearInterpolation(const rfacLinearInterpolation& toCopy)
{
  dataPoints = toCopy.dataPoints;
}

rfacLinearInterpolation::rfacLinearInterpolation()
{

}

rfacLinearInterpolation::~rfacLinearInterpolation()
{

}


///Needs huge amount of verification, unit test this!
double rfacLinearInterpolation::Eval(Double_t coordinate) const
{
  int closest = findClosest(coordinate);
  if(closest == (int)dataPoints.size()-1) ///If we are on the upper edge, use the point before to extrapolate.
    --closest;
  ///If we are on the lower edge, we will do the same (per default).

  double k = (dataPoints[closest+1].second-dataPoints[closest].second)/(dataPoints[closest+1].first-dataPoints[closest].first);

  double toReturn = dataPoints[closest].second + k*(coordinate-dataPoints[closest].first);
  return toReturn;
}



///This should be verified!!!!
int rfacLinearInterpolation::findClosest(Double_t toFind) const
{
  pair<int, int> bounds = make_pair(0, dataPoints.size()-1);

  while(bounds.second>bounds.first+1)
    {
      int mid = (bounds.second+bounds.first)/2;
      if( dataPoints[mid].first < toFind )
		{
		  bounds.first=mid;
		}
      else if(dataPoints[mid].first >= toFind)
		{
		  bounds.second=mid;
		}
    }
  return bounds.first;
}

vector<pair<Double_t, Double_t> > rfacLinearInterpolation::GetDataPoints() const
{
  return dataPoints;
}
