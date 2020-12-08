#include<iostream>
#include"Player.h"
#include"entity.h"
#include"object.h"

entity::entity()
{

}
int entity :: generateRandom(int min, int max)
{
	return rand() % (max - min) + min;
}