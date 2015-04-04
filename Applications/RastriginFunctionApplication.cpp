/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   R A S T R I G I N   F U N C T I O N   A P P L I C A T I O N              */
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

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "De Jong Function Application." << std::endl;


   srand( (unsigned)time( NULL ) );

   RastriginFunction rastriginFunction;

   int numberOfVariables = 5;

   rastriginFunction.setNumberOfVariables(numberOfVariables);
   
   Vector<double> argument(numberOfVariables, 1.0);
  
   // Evaluation
  
   double evaluation = rastriginFunction.getEvaluation(argument);
   
   std::cout << std::endl
             << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Analytical Gradient vector

   Vector<double> analyticalGradient = rastriginFunction.getGradient(argument);
   
   std::cout << std::endl
             << "Analytical gradient:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      std::cout << analyticalGradient[i] << " ";         
   }

   std::cout << std::endl;

   // Analytical Hessian matrix

   Matrix<double> hessian = rastriginFunction.getHessian(argument);
   
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

   Matrix<double> inverseHessian = rastriginFunction.getInverseHessian(argument);
   
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
