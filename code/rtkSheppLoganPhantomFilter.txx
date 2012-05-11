/*=========================================================================
 *
 *  Copyright RTK Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef __rtkSheppLoganPhantomFilter_txx
#define __rtkSheppLoganPhantomFilter_txx

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIteratorWithIndex.h>
#include "rtkHomogeneousMatrix.h"

namespace rtk
{
template< class TInputImage, class TOutputImage >
void SheppLoganPhantomFilter< TInputImage, TOutputImage >::GenerateData()
{
  m_SQPFunctor = SQPFunctionType::New();
  std::vector< REIType::Pointer > rei(10);
  unsigned int NumberOfFig = 10;

  for ( unsigned int j = 0; j < NumberOfFig; j++ )
    {
      rei[j] = REIType::New();
    }
  rei[0]->SetSemiPrincipalAxisX(88.32*0.7);
  rei[0]->SetSemiPrincipalAxisY(117.76*0.7);
  rei[0]->SetSemiPrincipalAxisZ(115.6*0.7);
  rei[0]->SetCenterX(0.);
  rei[0]->SetCenterY(0.);
  rei[0]->SetCenterZ(0.);
  rei[0]->SetRotationAngle(0.);
  rei[0]->SetMultiplicativeConstant(2.);

  rei[1]->SetSemiPrincipalAxisX(84.7872*0.7);
  rei[1]->SetSemiPrincipalAxisY(111.872*0.7);
  rei[1]->SetSemiPrincipalAxisZ(112.64*0.7);
  rei[1]->SetCenterX(0.);
  rei[1]->SetCenterY(0.);
  rei[1]->SetCenterZ(0.);
  rei[1]->SetRotationAngle(0.);
  rei[1]->SetMultiplicativeConstant(-0.98);

  rei[2]->SetSemiPrincipalAxisX(52.48*0.7);
  rei[2]->SetSemiPrincipalAxisY(20.48*0.7);
  rei[2]->SetSemiPrincipalAxisZ(26.88*0.7);
  rei[2]->SetCenterX(-28.16*0.7);
  rei[2]->SetCenterY(0.);
  rei[2]->SetCenterZ(-32.*0.7);
  rei[2]->SetRotationAngle(108.);
  rei[2]->SetMultiplicativeConstant(-0.02);

  rei[3]->SetSemiPrincipalAxisX(39.68*0.7);
  rei[3]->SetSemiPrincipalAxisY(14.08*0.7);
  rei[3]->SetSemiPrincipalAxisZ(28.16*0.7);
  rei[3]->SetCenterX(28.16*0.7);
  rei[3]->SetCenterY(0.);
  rei[3]->SetCenterZ(-32*0.7);
  rei[3]->SetRotationAngle(72.);
  rei[3]->SetMultiplicativeConstant(-0.02);

  rei[4]->SetSemiPrincipalAxisX(26.88*0.7);
  rei[4]->SetSemiPrincipalAxisY(32*0.7);
  rei[4]->SetSemiPrincipalAxisZ(64*0.7);
  rei[4]->SetCenterX(0.);
  rei[4]->SetCenterY(-44.8*0.7);
  rei[4]->SetCenterZ(-32*0.7);
  rei[4]->SetRotationAngle(0.);
  rei[4]->SetMultiplicativeConstant(0.02);

  rei[5]->SetSemiPrincipalAxisX(5.888*0.7);
  rei[5]->SetSemiPrincipalAxisY(5.888*0.7);
  rei[5]->SetSemiPrincipalAxisZ(5.888*0.7);
  rei[5]->SetCenterX(0.);
  rei[5]->SetCenterY(-12.8*0.7);
  rei[5]->SetCenterZ(-32*0.7);
  rei[5]->SetRotationAngle(0.);
  rei[5]->SetMultiplicativeConstant(0.02);

  rei[6]->SetSemiPrincipalAxisX(5.888*0.7);
  rei[6]->SetSemiPrincipalAxisY(2.944*0.7);
  rei[6]->SetSemiPrincipalAxisZ(2.56*0.7);
  rei[6]->SetCenterX(-10.24*0.7);
  rei[6]->SetCenterY(83.2*0.7);
  rei[6]->SetCenterZ(-32*0.7);
  rei[6]->SetRotationAngle(0.);
  rei[6]->SetMultiplicativeConstant(0.01);

  rei[7]->SetSemiPrincipalAxisX(5.888*0.7);
  rei[7]->SetSemiPrincipalAxisY(2.944*0.7);
  rei[7]->SetSemiPrincipalAxisZ(2.56*0.7);
  rei[7]->SetCenterX(7.68*0.7);
  rei[7]->SetCenterY(83.2*0.7);
  rei[7]->SetCenterZ(-32*0.7);
  rei[7]->SetRotationAngle(90.);
  rei[7]->SetMultiplicativeConstant(0.01);

  rei[8]->SetSemiPrincipalAxisX(7.168*0.7);
  rei[8]->SetSemiPrincipalAxisY(5.12*0.7);
  rei[8]->SetSemiPrincipalAxisZ(12.8*0.7);
  rei[8]->SetCenterX(7.68*0.7);
  rei[8]->SetCenterY(13.44*0.7);
  rei[8]->SetCenterZ(80.*0.7);
  rei[8]->SetRotationAngle(90.);
  rei[8]->SetMultiplicativeConstant(0.02);

  rei[9]->SetSemiPrincipalAxisX(7.168*0.7);
  rei[9]->SetSemiPrincipalAxisY(7.168*0.7);
  rei[9]->SetSemiPrincipalAxisZ(12.8*0.7);
  rei[9]->SetCenterX(0.);
  rei[9]->SetCenterY(-12.8*0.7);
  rei[9]->SetCenterZ(80.*0.7);
  rei[9]->SetRotationAngle(0.);
  rei[9]->SetMultiplicativeConstant(-0.02);


  for ( unsigned int i = 0; i < NumberOfFig; i++ )
    {
    if ( i == ( NumberOfFig - 1 ) ) //last case
      {
      if(i==0) //just one ellipsoid
        rei[i]->SetInput( rei[i]->GetOutput() );
      else
        rei[i]->SetInput( rei[i-1]->GetOutput() );
      rei[i]->SetGeometry( this->GetGeometry() );
      }

    if (i>0) //other cases
      {
      rei[i]->SetInput( rei[i-1]->GetOutput() );
      rei[i]->SetGeometry( this->GetGeometry() );
      }

    else //first case
      {
      rei[i]->SetInput( this->GetInput() );
      rei[i]->SetGeometry( this->GetGeometry() );
      }
    }
  //Update
  rei[NumberOfFig - 1]->Update();
  this->GraftOutput( rei[NumberOfFig - 1]->GetOutput() );
}
} // end namespace rtk

#endif