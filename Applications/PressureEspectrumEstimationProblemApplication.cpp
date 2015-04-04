/************************************************************************/
/*                                                                      */ 
/*   F l o o d   Neural Network                                         */
/*                                                                      */
/*   T E M P L A T E   A P P L I C A T I O N                            */
/*                                                                      */
/*   Roberto Lopez                                                      */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)  */
/*   Technical University of Catalonia (UPC)                            */
/*   Barcelona, Spain                                                   */
/*   E-mail: rlopez@cimne.upc.edu                                       */ 
/*                                                                      */  
/************************************************************************/

/// This main function can be used as a template for constructing any 
/// application with Flood.  

// System includes

#include <iostream>
#include <time.h>

// Utilities includes

#include "../Library/Utilities/Vector.h"
#include "../Library/Utilities/Matrix.h"

#include "../Library/Utilities/InputTargetDataSet.h"
#include "../Library/Utilities/IntegrationOfFunctions.h"

// Perceptron includes

#include "../Library/Perceptron/SigmoidPerceptron.h"
#include "../Library/Perceptron/LinearPerceptron.h"

// Multilayer perceptron includes

#include "../Library/MultilayerPerceptron/MultilayerPerceptron.h"

// Performance functional includes

#include "../Library/PerformanceFunctional/PressureEspectrumEstimationProblem.h"

// Learning algorithm includes

#include "../Library/TrainingAlgorithm/ConjugateGradient.h"
//#include "../Library/TrainingAlgorithm/GeneticAlgorithm.h"

using namespace Flood;

int main(void)
{
   std::cout << std::endl
             << "Flood Neural Network. "
             << "Pressure Espectrum Estimation Problem Application." << std::endl;

   std::cout << std::endl;

   srand( (unsigned)time( NULL ) );

   std::cout << std::endl;

   MultilayerPerceptron mlp;



   PressureEspectrumEstimationProblem peep(&mlp);

   peep.loadData("../Data/PressureEspectrumEstimationProblem/SoundPressureLevel.dat");

   peep.printData();

   ConjugateGradient cg(&peep);

   ga.setParameterX(.0554);

   Vector<double> c1c2c3 = ga.getMinimum();

   system("pause");

   return(0);
}  
