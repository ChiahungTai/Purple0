/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   G R A D I E N T   D E S C E N T   A P P L I C A T I O N                  */
/*                                                                            */
/*   Roberto Lopez                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)        */
/*   Technical University of Catalonia (UPC)                                  */
/*   Barcelona, Spain                                                         */
/*   E-mail: rlopez@cimne.upc.edu                                             */
/*                                                                            */
/******************************************************************************/

/// This main function can be used as a template for constructing any 
/// application with Purple.

// System includes

#include <iostream>
#include <time.h>
#include <stdexcept>

// Utilities includes

#include "../Purple/Utilities/Vector.h"
#include "../Purple/Utilities/Matrix.h"

// Objective function includes

#include "../Purple/ObjectiveFunction/DeJongFunction.h"

// Optimization algorithm includes

#include "../Purple/OptimizationAlgorithm/GradientDescent.h"

/// This application is an usage example of the GradientDescent class
/// in Purple.

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Gradient Descent Application." << std::endl;


   srand( (unsigned)time( NULL ) );

   // De Jong function object

   DeJongFunction deJongFunction;

   int numberOfVariables = 3;

   deJongFunction.setNumberOfVariables(numberOfVariables);

   Vector<double> lowerBound(numberOfVariables, -5.12);
   Vector<double> upperBound(numberOfVariables, -5.12);

   deJongFunction.setLowerBound(lowerBound);
   deJongFunction.setUpperBound(upperBound);

   // Gradient descent object

   GradientDescent gradientDescent(&deJongFunction);

   gradientDescent.setOptimalStepSizeMethod(GradientDescent::BrentMethod);

   gradientDescent.setOptimalStepSizeTolerance(1.0e-6);

   gradientDescent.setEvaluationGoal(0.0);
   gradientDescent.setGradientNormGoal(0.0);
   gradientDescent.setMaximumNumberOfIterations(100);
   gradientDescent.setMaximumTime(1000.0);
   
   gradientDescent.setShowPeriod(10);
  
   Vector<double> initialArgument(numberOfVariables, 1.0);

   gradientDescent.setInitialArgument(initialArgument);

   gradientDescent.print();
   
   gradientDescent.save("../Data/GradientDescent/GradientDescent.dat");
     
   Vector<double> minimalArgument = gradientDescent.getMinimalArgument();

   gradientDescent
   .saveOptimizationHistory("../Data/GradientDescent/OptimizationHistory.dat");

   std::cout << std::endl;         

   return(0);
}  


// Purple: An Open Source Numerical Optimization C++ Library.
// Copyright (C) 2006 Roberto Lopez
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
