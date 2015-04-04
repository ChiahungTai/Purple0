/******************************************************************************/
/*                                                                            */
/*   Purple: An Open Source Numerical Optimization C++ Library                */
/*                                                                            */
/*   P L A N E - C Y L I N D E R   A P P L I C A T I O N                      */
/*                                                                            */
/*   Roberto Lopez                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)        */
/*   Technical University of Catalonia (UPC)                                  */
/*   Barcelona, Spain                                                         */
/*   E-mail: rlopez@cimne.upc.edu                                             */
/*                                                                            */
/******************************************************************************/

// System includes

#include <iostream>
#include <time.h>
#include <stdexcept>

// Utilities includes

#include "../Purple/Utilities/Vector.h"
#include "../Purple/Utilities/Matrix.h"

// Objective function includes

#include "../Purple/ObjectiveFunction/PlaneCylinder.h"

using namespace Purple;

int main(void)
{
   std::cout << std::endl
             << "Purple: An Open Source Numerical Optimization C++ Library." 
             << std::endl
             << "Plane Cylinder Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   PlaneCylinder planeCylinder;
   planeCylinder.setPenalty(100.0);
   int numberOfVariables = planeCylinder.getNumberOfVariables();
   
   Vector<double> argument(numberOfVariables, 1.2);

   // Evaluation
  
   double evaluation = planeCylinder.getEvaluation(argument);
   
   std::cout << std::endl
             << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = planeCylinder.getGradient(argument);
   
   std::cout << std::endl
             << "Gradient:" << std::endl;
             
   for(int i = 0; i < numberOfVariables; i++)
   {
      std::cout << gradient[i] << " ";         
   }

   std::cout << std::endl;

   // Hessian matrix

   Matrix<double> hessian = planeCylinder.getHessian(argument);
   
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

   Matrix<double> inverseHessian = planeCylinder.getInverseHessian(argument);
   
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
