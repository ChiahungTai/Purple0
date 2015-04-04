################################################################################
#                                                                              # 
#   Purple: An Open Source Numerical Optimization C++ Library                  #
#                                                                              #
#   M A K E F I L E                                                            #
#                                                                              #
#   Roberto Lopez                                                              # 
#   International Center for Numerical Methods in Engineering (CIMNE)          #
#   Technical University of Catalonia (UPC)                                    #
#   Barcelona, Spain                                                           #
#   E-mail: rlopez@cimne.upc.edu                                               #
#                                                                              #
################################################################################


objects = TemplateApplication.o \
 	  ObjectiveFunction.o \
          DeJongFunction.o \
          RosenbrockFunction.o \
          RastriginFunction.o \
          PlaneCylinder.o \
          OptimizationAlgorithm.o \
          GradientDescent.o \
          ConjugateGradient.o \
          NewtonMethod.o \
          RandomSearch.o \
          EvolutionaryAlgorithm.o

Purple: $(objects)
	g++ $(objects) -o Purple

# Main function

TemplateApplication.o: ../Applications/TemplateApplication.cpp
	g++ -c ../Applications/TemplateApplication.cpp -o TemplateApplication.o

# Objective function

ObjectiveFunction.o: ../Purple/ObjectiveFunction/ObjectiveFunction.cpp
	g++ -c ../Purple/ObjectiveFunction/ObjectiveFunction.cpp -o  ObjectiveFunction.o

DeJongFunction.o: ../Purple/ObjectiveFunction/DeJongFunction.cpp
	g++ -c ../Purple/ObjectiveFunction/DeJongFunction.cpp -o DeJongFunction.o

RosenbrockFunction.o: ../Purple/ObjectiveFunction/RosenbrockFunction.cpp
	g++ -c ../Purple/ObjectiveFunction/RosenbrockFunction.cpp -o RosenbrockFunction.o

RastriginFunction.o: ../Purple/ObjectiveFunction/RastriginFunction.cpp
	g++ -c ../Purple/ObjectiveFunction/RastriginFunction.cpp -o RastriginFunction.o

PlaneCylinder.o: ../Purple/ObjectiveFunction/PlaneCylinder.cpp
	g++ -c ../Purple/ObjectiveFunction/PlaneCylinder.cpp -o PlaneCylinder.o


# Optimization algorithm

OptimizationAlgorithm.o: ../Purple/OptimizationAlgorithm/OptimizationAlgorithm.cpp
	g++ -c ../Purple/OptimizationAlgorithm/OptimizationAlgorithm.cpp -o OptimizationAlgorithm.o

GradientDescent.o: ../Purple/OptimizationAlgorithm/GradientDescent.cpp
	g++ -c ../Purple/OptimizationAlgorithm/GradientDescent.cpp -o GradientDescent.o

ConjugateGradient.o: ../Purple/OptimizationAlgorithm/ConjugateGradient.cpp
	g++ -c ../Purple/OptimizationAlgorithm/ConjugateGradient.cpp -o ConjugateGradient.o

NewtonMethod.o: ../Purple/OptimizationAlgorithm/NewtonMethod.cpp
	g++ -c ../Purple/OptimizationAlgorithm/NewtonMethod.cpp -o NewtonMethod.o

RandomSearch.o: ../Purple/OptimizationAlgorithm/RandomSearch.cpp
	g++ -c ../Purple/OptimizationAlgorithm/RandomSearch.cpp -o RandomSearch.o

EvolutionaryAlgorithm.o: ../Purple/OptimizationAlgorithm/EvolutionaryAlgorithm.cpp
	g++ -c ../Purple/OptimizationAlgorithm/EvolutionaryAlgorithm.cpp -o EvolutionaryAlgorithm.o


clean:
	rm $(objects) Purple


# Purple: An Open Source Numerical Optimization C++ Library.
# Copyright (C) 2006 Roberto Lopez
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
