#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int main(){

    //check if the copy constructor is deep copy
    Dog a;
    Dog b = a;

    Animal *savana[10];

    //instances of dogs
    for(int i = 0; i < 5; i++){
        savana[i] = new Dog();
    }

    //instances of cats
    for(int i = 5 ; i < 9 ; i++){
        savana[i] = new Cat();
    }
    //instances of animal
    savana[9] = new Animal();
    

    //testing the sound
    savana[0]->makeSound();
    savana[5]->makeSound();
    savana[9]->makeSound();

    //deleting the animals
    for(int i = 0; i < 10; i++){
        delete savana[i];
    }
    return 0;
}