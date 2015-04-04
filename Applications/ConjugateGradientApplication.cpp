/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   C O N J U G A T E   G R A D I E N T   A P P L I C A T I O N              */
/*                                                                            */
/*   Roberto Lopez                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)        */
/*   Technical University of Catalonia (UPC)                                  */
/*   Barcelona, Spain                                                         */
/*   E-mail: rlopez@cimne.upc.edu                                             */
/*                                                                            */
/******************************************************************************/

/// This application is an usage example of the ConjugateGradient class
/// in Purple.

// System includes

#include <iostream>
#include <time.h>
#include <stdexcept>

// Utilities includes

#include "../Purple/Utilities/Vector.h"
#include "../Purple/Utilities/Matrix.h"

// Objective function includes

#include "../Purple/ObjectiveFunction/RosenbrockFunction.h"

// Optimization algorithm includes

#include "../Purple/OptimizationAlgorithm/ConjugateGradient.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Conjugate Gradient Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Rosenbrock function object

   RosenbrockFunction rosenbrockFunction;

   int numberOfVariables = 10;

   rosenbrockFunction.setNumberOfVariables(numberOfVariables);

   Vector<double> lowerBound(numberOfVariables, -5.12);
   Vector<double> upperBound(numberOfVariables, 5.12);

   rosenbrockFunction.setLowerBound(lowerBound);
   rosenbrockFunction.setUpperBound(upperBound);

   // Conjugate gradient object

   ConjugateGradient conjugateGradient(&rosenbrockFunction);

   conjugateGradient.setSearchDirectionMethod(ConjugateGradient::FletcherReeves);
   conjugateGradient.setOptimalStepSizeMethod(ConjugateGradient::BrentMethod);

   conjugateGradient.setOptimalStepSizeTolerance(1.0e-6);

   conjugateGradient.setEvaluationGoal(0.0);
   conjugateGradient.setGradientNormGoal(0.0);
   conjugateGradient.setMaximumNumberOfIterations(1000);
   conjugateGradient.setMaximumTime(1000.0);
    
   conjugateGradient.setShowPeriod(100);
  
   Vector<double> initialArgument(numberOfVariables, 1.2);

   conjugateGradient.setInitialArgument(initialArgument);
   
   conjugateGradient.print();
   
   conjugateGradient.save("../Data/ConjugateGradient/ConjugateGradient.dat");
   
   Vector<double> minimalArgument = conjugateGradient.getMinimalArgument();

   conjugateGradient
   .saveOptimizationHistory("../Data/ConjugateGradient/OptimizationHistory.dat");

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

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
