#include <stdio.h>
#include <stdlib.h>

int addition(int x, int y)
{
  return x + y
}

int subtraction(int x, int y)
{
  return x - y
}

int division(int x, int y)
{
  return x / y
}

int mutliplcation(int x, int y)
{
  return x * y
}

int main(int argv, char* []argc)
{
  if (argv < 3)
  {
    fprintf(stderr, "%d Arguments Provided, Need 3", argv)
  }
  else 
  {
    switch (argc)
    {

