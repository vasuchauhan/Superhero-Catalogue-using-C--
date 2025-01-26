# Superhero Catalogue in C++

### This C++ code exemplifies various essential object-oriented programming concepts, such as classes, inheritance, polymorphism, encapsulation, and dynamic memory management. It allows users to interact with superheroes and sidekicks, add them to a catalog, display their details, and then exit the program. Additionally, it showcases additional functionalities like method overriding, error handling, and dynamic memory allocation.

1. ***Classes***: The code defines three classes - Superhero, Sidekick, and SuperheroCatalog. Each class encapsulates data and behavior related to superheroes and sidekicks.
2. ***Inheritance***: The Sidekick class inherits from the Superhero class, illustrating the concept of inheritance in OOP. This allows Sidekick to inherit properties and methods from its superclass (Superhero) and add its own unique properties and methods.
3. ***Polymorphism***: Polymorphism is demonstrated through method overriding. The showDetails method in the Superhero class is marked as virtual, and Sidekick overrides this method. When you call showDetails on a Sidekick object, it exhibits polymorphic behavior by invoking the overridden method.
4. ***Encapsulation***: Data members in the classes (e.g., name, power) are declared as private or protected, demonstrating encapsulation. Public getter methods (e.g., getName()) allow controlled access to these members.
5. ***Constructor Overloading***: Multiple constructors are defined in both the Superhero and Sidekick classes, showcasing constructor overloading. This allows object creation with different sets of parameters.
6. ***Friend Functions***: The introduce function is declared as a friend of the Superhero class, enabling it to access private members of the class.
7. ***Static Members***: The code uses static members (e.g., totalSuperheroes) to track information shared by all instances of a class.

