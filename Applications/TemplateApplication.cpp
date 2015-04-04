/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   T E M P L A T E   A P P L I C A T I O N                                  */
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
#include "../Purple/ObjectiveFunction/RosenbrockFunction.h"
#include "../Purple/ObjectiveFunction/RastriginFunction.h"
#include "../Purple/ObjectiveFunction/PlaneCylinder.h"

// Optimization algorithm includes

#include "../Purple/OptimizationAlgorithm/GradientDescent.h"
#include "../Purple/OptimizationAlgorithm/ConjugateGradient.h"
#include "../Purple/OptimizationAlgorithm/NewtonMethod.h"
#include "../Purple/OptimizationAlgorithm/RandomSearch.h"
#include "../Purple/OptimizationAlgorithm/EvolutionaryAlgorithm.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Template Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   std::cout << std::endl;

   return(0);
}  
