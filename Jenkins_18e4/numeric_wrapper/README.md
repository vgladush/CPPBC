# SafeNumeric template wrapper

Implement SafeNumeric<T> template class that wraps built-in types
(test it with: int,  unsigned int, short, double, float)
 and throws exception SafeNumeric_Overflow if some operation causes overflow.

Note, give this generic class "fat" interface, i.e. define all possible operations for all types above.
If some template parameter type does not support given operation then SafeNumeric_InvalidOperation should be thrown.

Same way as for TInt class wrapper constructor from string should raise SafeNumeric_InvalidInput exception if value has "garbage".

Your implementation is not necessary should be "ready-to-production" code
so may still have some bugs.

Consider spending some reasonable amount of time to cover all base operations,
make sure you have all unit tests passed and you handle all type specific limitations (i.e. handle all SafeNumeric_InvalidOperation cases) and only then you might want to make further improvements.

The list of files which are allowed to modify:
* project/numeric_wrapper.h
* project/numeric_wrapper.hpp


### Hint:
There are many ways to convert string to built-in types.
If you stuck with this, one possible way is to use `std::ostringstream` (but you are free to use whatever else):

```cpp
// be aware of std::fixed manipulator to convert without loosing precision
// double to std::ostringstream
template<class T> convert(const std::string& s)
{
   T tmp;
   std::istringstream is(s);
   is >> tmp;
   if (is.fail())
   {
      // report error ;
   }
   return tmp;
}
```

GL BaseCamp Team

