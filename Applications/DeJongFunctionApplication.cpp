/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   D E   J O N G   F U N C T I O N   A P P L I C A T I O N                  */
/*                                                                            */
/*   Roberto Lopez                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)        */
/*   Technical University of Catalonia (UPC)                                  */
/*   Barcelona, Spain                                                         */
/*   E-mail: rlopez@cimne.upc.edu                                             */
/*                                                                            */
/******************************************************************************/

/// This main function is an example application of the DeJongFunction class
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

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "De Jong Function Application." << std::endl;


   srand( (unsigned)time( NULL ) );

   DeJongFunction deJongFunction;

   int numberOfVariables = 3;

   deJongFunction.setNumberOfVariables(numberOfVariables);
   
   Vector<double> argument(numberOfVariables, 1.0);
  
   // Evaluation
  
   double evaluation = deJongFunction.getEvaluation(argument);
   
   std::cout << std::endl
             << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = deJongFunction.getGradient(argument);
   
   std::cout << std::endl
             << "Gradient:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      std::cout << gradient[i] << " ";         
   }

   std::cout << std::endl;

   // Hessian matrix

   Matrix<double> hessian = deJongFunction.getHessian(argument);
   
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

   Matrix<double> inverseHessian = deJongFunction.getInverseHessian(argument);
   
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
