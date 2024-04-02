# Filament
A simple ECS game engine for tiny-scope games.

## What is Filament?
Filament is a WIP ECS game engine made in C++ for making smaller games. 
It's also a project I've wanted to build for a while now, and I've finally sat down and tried to do it.
Filament prioritizes ease of development and ease of extensibility over performance (for now).

## What isn't Filament?
- A replacement for any established game engine (Unity, Unreal, Godot, etc.)
- A performance-focused game engine
- A "good" (performant, proper) ECS implementation

## Dependencies
- Make
- GLEW
- GLFW
- OpenGL 3.3

## Supported Platforms
- [x] Mac (x86_64)
- [ ] Max (ARM)
- [ ] Windows
- [ ] Linux

## FAQ
### What is an ECS?
ECS stands for <ins>E</ins>ntity <ins>C</ins>omponent <ins>S</ins>ystem. 
- Components: Within an ECS, all data about the game and entitites are stored in components. A component can be as small as a `bool isOnFire` or as complex as a `Mesh` type. All components are stored in arrays, where each index represents a different entity.

- Entity: Within an ECS (as opposed to a normal type of game engine), an Entity *does not story any data*. Instead, an entity is just an index into all of the component types associated with it. For example, an Entity representing a player object would be the same index into the `Mesh` and `Controller` components.

- Systems: A System is just some type of function (or in the case of C++, potentially a functor) that operates on one more components. 
For example, a `doPhysics` system might operate on both a `Velocity` and a `Transform` component. 

### Aren't ECS systems made to be performant? Why do you say that Filament's goal is not to be performant?
Yes, ECS systems are typically designed to be as performant as possible and are a great example of DOD (Data Oriented Design). 
The format of having arrays of components lends itself well to CPU caching and CPU prefetching, which are some of the ways in which modern 
CPUs achieve such high performace. 

However, because ECS is a system based on composition over inheritance, it is interesting from an architectural point of view. Emergent
behavior is easy in an ECS, since the system does not rely on a strict hierarchy of entitys and all of their potential behaviors.

Because the scope of the games I plan on making is small, as long as the ECS isn't too unoptimized, I shouldn't have to worry about
performance. For this project, I'm far more interested in the architecture side of things rather than the performance side of things.

Plus, given that this is my first game engine, the goal is to get something working, not necessarily something hyper-optomized.

### Why OpenGL and not Vulkan?
Simply put, I don't want to add an extra month to the development process just to get basic rendering work done. However, if the engine
is made correctly, swapping in a Vulkan system should be trivial. 
