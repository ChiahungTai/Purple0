/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   N E W T O N   M E T H O D   A P P L I C A T I O N                        */
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

#include "../Purple/OptimizationAlgorithm/NewtonMethod.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Newton Method Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // De Jong function object

   DeJongFunction deJongFunction;

   int numberOfVariables = 3;

   deJongFunction.setNumberOfVariables(numberOfVariables);

   Vector<double> lowerBound(numberOfVariables, -5.12);
   Vector<double> upperBound(numberOfVariables, 5.12);

   deJongFunction.setLowerBound(lowerBound);
   deJongFunction.setUpperBound(upperBound);

   // Newton method object

   NewtonMethod newtonMethod(&deJongFunction);

   newtonMethod.setEvaluationGoal(0.001);
   newtonMethod.setGradientNormGoal(0.0);
   newtonMethod.setMaximumNumberOfIterations(1);
   newtonMethod.setMaximumTime(1000.0);
   
   newtonMethod.setShowPeriod(1);
  
   Vector<double> initialArgument(numberOfVariables, 1.0);

   newtonMethod.setInitialArgument(initialArgument);

   newtonMethod.load("../Data/NewtonMethod/NewtonMethod.dat");
  
   newtonMethod.print();
   
   newtonMethod.save("../Data/NewtonMethod/NewtonMethod.dat");
      
   Vector<double> minimalArgument = newtonMethod.getMinimalArgument();

   newtonMethod
   .saveOptimizationHistory("../Data/NewtonMethod/OptimizationHistory.dat");

   std::cout << std::endl;         

   return(0);
}  
