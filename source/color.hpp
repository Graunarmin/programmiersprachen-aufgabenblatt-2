# ifndef COLOR_HPP
# define COLOR_HPP

//color class definition
struct Color{

	float r_;
	float g_;
	float b_;

	Color(float a);
	//Konstruktor, der alle Variablen auf 0.0 setzt

	Color(float r, float g, float b);
	//Konstruktor, der einen Wert für jede Variable entgegen nimmt

};


# endif // COLOR_HPP