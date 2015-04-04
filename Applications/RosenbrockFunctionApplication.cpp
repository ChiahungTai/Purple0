/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   R O S E N B R O C K   F U N C T I O N   A P P L I C A T I O N            */
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

#include "../Purple/ObjectiveFunction/RosenbrockFunction.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Rosenbrock Function Application." << std::endl;


   srand( (unsigned)time( NULL ) );

   RosenbrockFunction rosenbrockFunction;

   int numberOfVariables = 5;

   rosenbrockFunction.setNumberOfVariables(numberOfVariables);
   
   Vector<double> argument(numberOfVariables, 1.2);
  
   // Evaluation
  
   double evaluation = rosenbrockFunction.getEvaluation(argument);
   
   std::cout << std::endl
             << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = rosenbrockFunction.getGradient(argument);
   
   std::cout << std::endl
             << "Gradient:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      std::cout << gradient[i] << " ";         
   }

   std::cout << std::endl;

   // Hessian matrix

   Matrix<double> hessian = rosenbrockFunction.getHessian(argument);
   
   std::cout << std::endl
             << "Hessian:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      for(int j = 0; j < numberOfVariables; j++)
      {
         std::cout << hessian[i][j] << " ";         
      }
      
      std::cout << std::endl;
   }

   // Inverse Hessian matrix

   Matrix<double> inverseHessian 
   = rosenbrockFunction.getInverseHessian(argument);
   
   std::cout << std::endl
             << "Inverse Hessian:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      for(int j = 0; j < numberOfVariables; j++)
      {
         std::cout << inverseHessian[i][j] << " ";         
      }
      
      std::cout << std::endl;
   }

   std::cout << std::endl;         

   return(0);
}  
