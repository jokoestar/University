#include <iostream>
#include <string>
using namespace std;
//This is a rectangle. It has 4 sides. It's instance variables are height and width. It is represented with '#' characters
class rectangle
{
  private:
    int height;//This is the vertical dimension of the rectangle
    int width;//This is the horizontal dimension of the rectangle
  public:
    rectangle(); //This is the default constructor for the class. It initializes a rectangle with a height of 1 and width of 1
    rectangle(int Height, int Width); //This is a constructor of the class. It has parameters Height and Width and sets Height and Width to height and width
    void add(int addHeight, int addWidth); //This function takes addHeight and addWidth as parameters. height and width are set to the sums of height and addHeight and width and addWidth respectively
    void set(int new_height, int new_width); //This function takes new_height and new_width as parameters and changes the values of height to new_height and width to new_width
    void draw(); //This function prints a representation of the rectangle using '#' characters
    bool is_square(); //This function returns true if the length and width are equal and false elsewise
    int get_height(); //This function returns the height
    int get_width(); //This function returns the width
};
/*  This  is the default constructor for the rectangle class
*   Precondition: There is available memory to allocate for a new rectangle object
*   Postcondition: A new rectangle object is created with a height of 1 and width of 1
*/
rectangle::rectangle()
{
  height = 1;
  width = 1;
}
/*  This is  a constructor for the rectangle class
*   @Param Height: This is an integer which height is set equal to
*   @Param Width: This is an integer which width is set equal to
*   Precondition: There is available memory to allocate for a new rectangle object
*   Postcondition: A new rectangle object is created with a height of Height and a width of Width
*/
rectangle::rectangle(int Height, int Width)
{
  height = Height;
  width = Width;
}
/*  This is a function which changes the instance variables of a rectangle object to a sum of the parameters and instance variables
*   @Param addHeight: This is an integer which height is added to
*   @Param addWidth: This is an integer which width is added to
*   Precondition: height and width are initialized
*   Postcondition: height and width gain a value equal to the sum of themselves and addHeight and addWidth respectively
*/
void rectangle::add(int addHeight, int addWidth)
{
  height += addHeight;
  width += addWidth;
}

/*  This is a function which changes the instance variables of a rectangle object to the parameters
*   @Param new_width: This is an integer which height is set equal to
*   @Param new_width: This is an integer which width is set equal to
*   Precondition: There is  memory for the rectangle object
*   Postcondition: The values of height and width are set to that of new_height and new_width
*/
void rectangle::set(int new_height, int new_width)
{
  height = new_height;
  width = new_width;
}

/*  This is a function which draws a rectangle on the console using '#' characters
*   Precondition: rectangle is initialized
*   Postcondition: a rectangle is drawn on the console
*/
void rectangle::draw()
{
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
      cout << '#';
    cout << '\n';
  }
}

/*  This is a function which tests whether the rectangle object is also a square
*   Precondition: The rectangle's instance variables are initialized
*   Postiondition: Returns true if the width and height are equal and false otherwise
*/
bool rectangle::is_square()
{
  return height == width;
}

/*  This is a function which returns the height of the rectangle
*   Precondition: height is initialized
*   Postcondition: Returns height;
*/
int rectangle::get_height()
{
  return height;
}


/*  This is a function which returns the width of the rectangle
*   Precondition: width is initialized
*   Postcondition: Returns width;
*/
int rectangle::get_width()
{
  return width;
}






int main() 
{
  // Declare 2 rectangles
  rectangle r1, r2;
  
  // Draw the unit rectangle
  cout << "unit rectangle" << endl;
  r1.draw();
  
  // Set, print dimensions and draw
  r1.set(4, 3);
  cout << "r1 is " << r1.get_height() << " x " << r1.get_width() << endl;
  r1.draw();
  
  // Assign, increment, print dimensions and draw
  r2 = r1;
  r2.add(3, 4);
  cout << "r2 is " << r2.get_height() << " x " << r2.get_width() << endl;
  r2.draw();
  // Prints to the console whether r2 is a square
  if (r2.is_square())
    cout << "r2 is a square" << endl;
  else
    cout << "r2 is not a square" << endl;
  return 0;
}