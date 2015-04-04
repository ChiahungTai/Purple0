/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   E V O L U T I O N A R Y   A L G O R I T H M   A P P L I C A T I O N      */
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

#include "../Purple/ObjectiveFunction/RastriginFunction.h"

// Optimization algorithm includes

#include "../Purple/OptimizationAlgorithm/EvolutionaryAlgorithm.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Evolutionary Algorithm Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Rastrigin function object

   RastriginFunction rastriginFunction;

   int numberOfVariables = 5;

   rastriginFunction.setNumberOfVariables(numberOfVariables);

   Vector<double> lowerBound(numberOfVariables, -5.12);
   Vector<double> upperBound(numberOfVariables, 5.12);
   
   rastriginFunction.setLowerBound(lowerBound);
   rastriginFunction.setUpperBound(upperBound);

   // Evolutionary algorithm object

   EvolutionaryAlgorithm evolutionaryAlgorithm(&rastriginFunction);
   
   evolutionaryAlgorithm
   .setFitnessAssignmentMethod(EvolutionaryAlgorithm::LinearRanking);

   evolutionaryAlgorithm
   .setSelectionMethod(EvolutionaryAlgorithm::StochasticUniversalSampling);

   evolutionaryAlgorithm
   .setRecombinationMethod(EvolutionaryAlgorithm::Intermediate);

   evolutionaryAlgorithm
   .setMutationMethod(EvolutionaryAlgorithm::Uniform);
   
   evolutionaryAlgorithm.setPopulationSize(10*numberOfVariables);
   
   evolutionaryAlgorithm.initPopulationAtRandom(lowerBound, upperBound);
   
   evolutionaryAlgorithm.setEvaluationGoal(0.001);
   evolutionaryAlgorithm.setMaximumNumberOfGenerations(1000);
   evolutionaryAlgorithm.setMaximumTime(1000.0);
   evolutionaryAlgorithm.setShowPeriod(100);

   evolutionaryAlgorithm.print();   
  
   Vector<double> minimalArgument = evolutionaryAlgorithm.getMinimalArgument();

   evolutionaryAlgorithm
   .save("../Data/EvolutionaryAlgorithm/EvolutionaryAlgorithm.dat");

   evolutionaryAlgorithm
   .saveOptimizationHistory("../Data/EvolutionaryAlgorithm/OptimizationHistory.dat");

   std::cout << std::endl;         

   system("pause");

   return(0);
}  
