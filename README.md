# The Simple Fast Physics Library for SFML

This is a basic 2D collision library for SFML.  Its is quite fast (although some future further optimizations are intended).  
It presents an API similar to SFML's API in that it is totally pointerless.  Simple games can be written with just stack allocation.

Its features and limitations are as follows:

## NUGET PACKAGE
https://www.nuget.org/packages/SFPhysics/

## FEATURES
* Fast collision detection and response.
* No internal memory allocation other then that done by library classes (e.g. list<T>)
* Pointerless API
* Hooks for responding to collisions and movement
* Collision bounds visualization (very useful for application debugging)

## LIMITATIONS
* Only supports Circular bounds and Axis-Aligned Bounding Boxes
* Only support simple hard bodies (no joints)
* Euler integrator can miss inter-frame collisions
* Currently only has prebuilt Physics SFML extensions for CircleShape, RectangleShape and Sprite
* Currently undocumented

## EXAMPLES
https://github.com/profK/Breakout2  

## PLANNED EXTENSIONS
* Physics SFML extensions for the rest of the SFML drawing types
* Location-bin based collision acceleration
* "Sleeping" based collision acceleration
* Documentation
  
## RELEASE NOTES
Version 1.0 has been released.  It is feature complkete and passses all the tests I have for it.
There may be bugs.  And documentation is still forthcoming.
