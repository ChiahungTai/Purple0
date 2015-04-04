/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   R A N D O M   S E A R C H   A P P L I C A T I O N                        */
/*                                                                            */
/*   Roberto Lopez                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)        */
/*   Technical University of Catalonia (UPC)                                  */
/*   Barcelona, Spain                                                         */
/*   E-mail: rlopez@cimne.upc.edu                                             */
/*                                                                            */
/******************************************************************************/

/// This application is an usage example of the RandomSearch class
/// in Purple.

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

#include "../Purple/OptimizationAlgorithm/RandomSearch.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Random Search Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // De Jong function object 

   DeJongFunction deJongFunction;

   int numberOfVariables = 10;

   deJongFunction.setNumberOfVariables(numberOfVariables);

   // Random search object

   RandomSearch randomSearch(&deJongFunction);

   randomSearch.setEvaluationGoal(0.001);
   randomSearch.setMaximumNumberOfIterations(100);
   randomSearch.setMaximumTime(1000.0);
   
   randomSearch.setShowPeriod(10);

   randomSearch.print();
   
   randomSearch.save("../Data/RandomSearch/RandomSearch.dat");
   
   Vector<double> minimalArgument = randomSearch.getMinimalArgument();

   randomSearch
   .saveOptimizationHistory("../Data/RandomSearch/OptimizationHistory.dat");

   std::cout << std::endl;         

   return(0);
}  
