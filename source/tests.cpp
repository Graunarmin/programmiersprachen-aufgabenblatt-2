#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

//Vector Tests

//Konstruktoren
TEST_CASE (" default_Constructor ", "[default_Constructor]")
{
Vec2 nullVector{}; //sollte Vektor mit x_ == y_ == 0 erzeugen

REQUIRE (nullVector.x_ == 0);
REQUIRE (nullVector.y_ == 0);
REQUIRE (nullVector.x_ == nullVector.y_);
}

TEST_CASE (" value_Constructor ", "[value_Constructor]")
{
Vec2 valueVector{5.4f,2.0f};
REQUIRE (valueVector.x_ == 5.4f);
REQUIRE (valueVector.y_ == 2.0f);
}

//Operatoren (Member)
TEST_CASE (" plusGleich ", "[plusGleich]")
{
Vec2 plusGleich1{1.0f,2.0f};
Vec2 plusGleich2{4.0f,6.0f};
Vec2 plusGleich3{0.0f,3.0f};

plusGleich1 += plusGleich2;
plusGleich2 += plusGleich3;
plusGleich3 += plusGleich1;

REQUIRE (plusGleich1.x_ == 5.0f);
REQUIRE (plusGleich1.y_ == 8.0f);
REQUIRE (plusGleich2.x_ == 4.0f);
REQUIRE (plusGleich2.y_ == 9.0f);
REQUIRE (plusGleich3.x_ == 5.0f);
REQUIRE (plusGleich3.y_ == 11.0f);
}

TEST_CASE (" minusGleich ", "[minusGleich]")
{
Vec2 minusGleich1{4.0f,2.0f};
Vec2 minusGleich2{2.0f,1.0f};
Vec2 minusGleich3{0.0f,1.0f};

minusGleich1 -= minusGleich2;
minusGleich2 -= minusGleich3;
minusGleich3 -= minusGleich1;

REQUIRE (minusGleich1.x_ == 2.0f);
REQUIRE (minusGleich1.y_ == 1.0f);
REQUIRE (minusGleich2.x_ == 2.0f);
REQUIRE (minusGleich2.y_ == 0.0f);
REQUIRE (minusGleich3.x_ == -2.0f);
REQUIRE (minusGleich3.y_ == 0.0f);
}

TEST_CASE (" malGleich ", "[malGleich]")
{
Vec2 malGleich1{4.0f,2.0f};
Vec2 malGleich2{2.5f,3.7f};
Vec2 malGleich3{1.0f,3.5f};
Vec2 malGleich4{1.4f,8.2f};

malGleich1 *= 2.5f;
malGleich2 *= 1.3;
malGleich3 *= -2.0f;
malGleich4 *= 0.0f;

REQUIRE (malGleich1.x_ == 10.0f);
REQUIRE (malGleich1.y_ == 5.0f);
REQUIRE (malGleich2.x_ == 3.25f);
REQUIRE (malGleich2.y_ == 4.81f);
REQUIRE (malGleich3.x_ == -2.0f);
REQUIRE (malGleich3.y_ == -7.0f);
REQUIRE (malGleich4.x_ == 0.0f);
REQUIRE (malGleich4.y_ == 0.0f);
}

TEST_CASE (" divGleich ", "[divGleich]"){

Vec2 divGleich1{4.0f,2.0f};
Vec2 divGleich2{3.5f,1.7f};
Vec2 divGleich3{0.0f,1.0f};
Vec2 divGleich4{1.0f,1.0f};

divGleich1 /= 2.0f;
divGleich2 /= 1.5f;
divGleich3 /= -3.0f;
divGleich4 /= 0.0f;

REQUIRE (divGleich1.x_ == 2.0f);
REQUIRE (divGleich1.y_ == 1.0f);
REQUIRE (divGleich2.x_ == Approx(2.333333f));
REQUIRE (divGleich2.y_ == Approx(1.133333f));
REQUIRE (divGleich3.x_ == 0.0f);
REQUIRE (divGleich3.y_ == Approx(-0.33333f));
}

//Operatoren (keine Member)
TEST_CASE (" plus ", "[plus]")
{
Vec2 plus1{1.3f, 2.6f};
Vec2 plus2{8.7f, 4.4f};

Vec2 summe = plus1 + plus2;
REQUIRE (summe.x_ == 10.0f);
REQUIRE (summe.y_ == 7.0f);
}

TEST_CASE (" minus ", "[minus]")
{
Vec2 minus1{3.5f, 10.0f};
Vec2 minus2{2.7f, 1.0f};

Vec2 differenz = minus1 - minus2;
REQUIRE (differenz.x_ == Approx(0.8f));
REQUIRE (differenz.y_ == 9.0f);
}

TEST_CASE (" mal ", "[mal]")
{
Vec2 mal1{2.3f, 5.1f};
Vec2 mal2{9.0f, 7.8f};

Vec2 skalar1 = mal1 * 2.0f;
Vec2 skalar2 = mal2 * 1.5f;

REQUIRE (skalar1.x_ == 4.6f);
REQUIRE (skalar1.y_ == 10.2f);
REQUIRE (skalar2.x_ == 13.5f);
REQUIRE (skalar2.y_ == Approx(11.7f));
}

TEST_CASE (" div ", "[div]")
{
Vec2 div1{4.0f, 2.0f};
Vec2 div2{9.3f, 6.3f};
Vec2 div3{8.1f, 2.4f};

Vec2 quotient1 = div1 / 2.0f;
Vec2 quotient2 = div2 / 3.3f;
Vec2 quotient3 = div3 / 0.0f;

REQUIRE (quotient1.x_ == 2.0f);
REQUIRE (quotient1.y_ == 1.0f);
REQUIRE (quotient2.x_ == Approx(2.81818f));
REQUIRE (quotient2.y_ == Approx(1.90909f));
REQUIRE_FALSE (quotient3.x_ == 0.0f);
REQUIRE (!(quotient3.y_ == 0.0f));
}

TEST_CASE (" mal2 ", "[mal2]")
{
Vec2 mal3{3.0f, 2.0f};
Vec2 mal4{4.7f, 0.0f};

Vec2 skalar3 = mal3 * 6.8f;
Vec2 skalar4 = mal4 * 2.0f;

REQUIRE (skalar3.x_ == Approx(20.4f));
REQUIRE (skalar3.y_ == Approx(13.6f));
REQUIRE (skalar4.x_ == Approx(9.4f));
REQUIRE (skalar4.y_ == Approx(0.0f));
}


//Matrizen Tests

//Konstruktoren
TEST_CASE (" default_MatrConstr ", "[default_MatrConstr]")
{
Mat2 identMatr{};

REQUIRE (identMatr.x1_ == 1.0f);
REQUIRE (identMatr.x2_ == 0.0f);
REQUIRE (identMatr.y1_ == 0.0f);
REQUIRE (identMatr.y2_ == 1.0f);
}

TEST_CASE (" value_Matr_Constr ", "[value_Matr_Constr]")
{
Mat2 valueMatr{2.0f, 3.3f, 5.1f, 7.5f};

REQUIRE (valueMatr.x1_ == 2.0f);
REQUIRE (valueMatr.x2_ == 3.3f);
REQUIRE (valueMatr.y1_ == 5.1f);
REQUIRE (valueMatr.y2_ == 7.5f);
}

//Operatoren

//Matrizenmultiplikation (2x2)
TEST_CASE (" matrizen_multiplikation ", "[matrizen_multiplikation]")
{
Mat2 multMat1{2.0f, 3.3f, 5.1f, 7.5f};
Mat2 multMat2{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 multMat3{0.0f, 8.2f, 0.0f, 0.0f};

multMat1 *= multMat2;
multMat2 *= multMat3;

REQUIRE (multMat1.x1_ == Approx(-22.06f));
REQUIRE (multMat1.x2_ == Approx(8.39f));
REQUIRE (multMat1.y1_ == Approx(-48.75f));
REQUIRE (multMat1.y2_ == Approx(21.12f));
REQUIRE (multMat2.x1_ == 0.0f);
REQUIRE (multMat2.x2_ == 20.5f);
REQUIRE (multMat2.y1_ == 0.0f);
REQUIRE (multMat2.y2_ == -67.24f);
}

TEST_CASE (" multMat ", "[multMat]")
{
Mat2 mult1{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mult2{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 mult3{0.0f, 8.2f, 0.0f, 0.0f};

Mat2 product = mult1 * mult2;
Mat2 product2 = mult2 * mult3;
REQUIRE (product.x1_ == Approx(5.0f));
REQUIRE (product.x2_ == Approx(7.4f));
REQUIRE (product.y1_ == Approx(74.25f));
REQUIRE (product.y2_ == Approx(16.62f));
REQUIRE (product2.x1_ == Approx(0.0f));
REQUIRE (product2.x2_ == Approx(20.5f));
REQUIRE (product2.y1_ == Approx(0.0f));
REQUIRE (product2.y2_ == Approx(-67.24f));
}


//Multiplikationen Vektor mit Matrix
TEST_CASE (" matVec_mult ", "[matVec_mult]")
{
Mat2 mMult1{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mMult2{2.5f, 3.7f, -8.2f, 0.3f};
Vec2 vMult1{-2.3f, 5.1f};
Vec2 vMult2{4.7f, 0.0f};

Vec2 product = mMult1 * vMult1;
Vec2 product2 = mMult2 * vMult2;
Vec2 product3 = mMult2 * vMult1;
REQUIRE (product.x_ == Approx(-4.6f));
REQUIRE (product.y_ == Approx(-49.98f));
REQUIRE (product2.x_ == Approx(11.75f));
REQUIRE (product2.y_ == Approx(-38.54f));
REQUIRE (product3.x_ == Approx(13.12f));
REQUIRE (product3.y_ == Approx(20.39f));
}

TEST_CASE (" vecMat_mult ", "[vecMat_mult]")
{
Mat2 mMult3{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mMult4{2.5f, 3.7f, -8.2f, 0.3f};
Vec2 vMult3{-2.3f, 5.1f};
Vec2 vMult4{4.7f, 0.0f};

Vec2 product4 = vMult3 * mMult3;
Vec2 product5 = vMult4 * mMult4;
Vec2 product6 = vMult3 * mMult4;
REQUIRE (product4.x_ == Approx(-4.6f));
REQUIRE (product4.y_ == Approx(-49.98f));
REQUIRE (product5.x_ == Approx(11.75f));
REQUIRE (product5.y_ == Approx(-38.54f));
REQUIRE (product6.x_ == Approx(13.12f));
REQUIRE (product6.y_ == Approx(20.39f));
}

//Determinante
TEST_CASE (" determinante ", "[determinante]")
{
Mat2 detMat1{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 detMat2{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 detMat3{3.732f, 0.0f, -89.6f, 0.0f};

REQUIRE (detMat1.det() == 31.09f);
REQUIRE (detMat2.det() == -15.0f);
REQUIRE (detMat3.det() == 0.0f);
}

//Inverse
TEST_CASE (" inverse ", "[inverse]")
{
Mat2 mA{2.0f, -3.0f, 1.0f, 5.0f};
Mat2 invMat1 = inverse(mA);
Mat2 mB{};
Mat2 invMat2 = inverse(mB);
Mat2 mC{2.3f, 4.8f, 0.0f, 0.0f};
Mat2 invMat3 = inverse(mC);

REQUIRE (invMat1.x1_ == Approx(0.38461));
REQUIRE (invMat1.x2_ == Approx(0.23076));
REQUIRE (invMat1.y1_ == Approx(-0.07692));
REQUIRE (invMat1.y2_ == Approx(0.15384));
REQUIRE (invMat2.x1_ == 1.0f);
REQUIRE (invMat2.x2_ == 0.0f);
REQUIRE (invMat2.y1_ == 0.0f);
REQUIRE (invMat2.y2_ == 1.0f);
REQUIRE (invMat3.x1_ == -1.0f);
REQUIRE (invMat3.x2_ == -1.0f);
REQUIRE (invMat3.y1_ == -1.0f);
REQUIRE (invMat3.y2_ == -1.0f);
}

//Transponieren
TEST_CASE (" transpose ", "[transpose]")
{
Mat2 mA{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 mTrans1 = transpose(mA);
Mat2 mB{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mTrans2 = transpose(mB);

REQUIRE (mTrans1.x1_ == 2.5f);
REQUIRE (mTrans1.x2_ == -8.2f);
REQUIRE (mTrans1.y1_ == 3.7f);
REQUIRE (mTrans1.y2_ == 0.3f);
REQUIRE (mTrans2.x1_ == 2.0f);
REQUIRE (mTrans2.x2_ == 5.1f);
REQUIRE (mTrans2.y1_ == 0.0f);
REQUIRE (mTrans2.y2_ == -7.5f);
}

//Rotationsmatrix
TEST_CASE (" rotation ", "[rotation]")
{

Mat2 mRot1 = make_rotation_mat2(M_PI / 2);
Mat2 mRot2 = make_rotation_mat2(0);
Mat2 mRot3 = make_rotation_mat2(-2.5);

REQUIRE (mRot1.x1_ == Approx(0.0f));
REQUIRE (mRot1.x2_ == Approx(-1.0f));
REQUIRE (mRot1.y1_ == Approx(1.0f));
REQUIRE (mRot1.y2_ == Approx(0.0f));
REQUIRE (mRot2.x1_ == 1.0f);
REQUIRE (mRot2.x2_ == 0.0f);
REQUIRE (mRot2.y1_ == 0.0f);
REQUIRE (mRot2.y2_ == 1.0f);
REQUIRE (mRot3.x1_ == Approx(-0.80114f));
REQUIRE (mRot3.x2_ == Approx(0.59847f));
REQUIRE (mRot3.y1_ == Approx(-0.59847f));
REQUIRE (mRot3.y2_ == Approx(-0.80114f));
}

//Color Test
TEST_CASE (" default_color_Constr ", "[default_color_Constr]")
{
Color black{};

REQUIRE (black.r_ == 0.0f);
REQUIRE (black.g_ == 0.0f);
REQUIRE (black.b_ == 0.0f);
}

TEST_CASE (" color_Constr_one ", "[color_Constr_one]")
{
Color weirdColor{1.0f};

REQUIRE (weirdColor.r_ == 1.0f);
REQUIRE (weirdColor.g_ == 1.0f);
REQUIRE (weirdColor.b_ == 1.0f);
}

TEST_CASE (" color_Constr ", "[color_Constr]")
{
Color anyColor{1.0f, 0.0f, 1.0f};

REQUIRE (anyColor.r_ == 1.0f);
REQUIRE (anyColor.g_ == 0.0f);
REQUIRE (anyColor.b_ == 1.0f);
}


//Tests for Circle
//Konstruktortests
TEST_CASE (" default_circle_Constr ", "[default_circle_Constr]")
{
Circle identCircle{};

REQUIRE (identCircle.radius_ == 1.0f);
REQUIRE (identCircle.center_.x_ == 0.0f);
REQUIRE (identCircle.center_.y_ == 0.0f);
REQUIRE (identCircle.clr_.r_ == 0.0f);
REQUIRE (identCircle.clr_.g_ == 0.0f);
REQUIRE (identCircle.clr_.b_ == 0.0f);
}

TEST_CASE (" circle_Constr ", "[circle_Constr]")
{
Circle circle{2.7f, Vec2{1.2f, -3.5}, Color{1.0f}};

REQUIRE (circle.radius_ == 2.7f);
REQUIRE (circle.center_.x_ == 1.2f);
REQUIRE (circle.center_.y_ == -3.5f);
REQUIRE (circle.clr_.r_ == 1.0f);
REQUIRE (circle.clr_.g_ == 1.0f);
REQUIRE (circle.clr_.b_ == 1.0f);
}

//getter
TEST_CASE (" get_Radius ", "[get_Radius]")
{

Circle c1{2.7f, Vec2{1.2f, -3.5}, Color{}};
float t = c1.getRadius();
Circle c2{8.5f, Vec2{4.8f, 5.5},Color{}};

REQUIRE (t == 2.7f);
REQUIRE (c2.getRadius() == 8.5f);
}

TEST_CASE (" get_Center ", "[get_Center]")
{

Circle c1{2.7f, Vec2{1.2f, -3.5}, Color{}};
Vec2 c = c1.getCenter();
Circle c2{8.5f, Vec2{-4.8f, 0.0f}, Color{}};

REQUIRE (c.x_ == 1.2f);
REQUIRE (c.y_ == -3.5f);
REQUIRE (c2.getCenter().x_ == -4.8f);
REQUIRE (c2.getCenter().y_ == 0.0f);
}

TEST_CASE (" get_Circ_Color ", "[get_Circ_Color]")
{

Circle c1{2.7f, Vec2{1.2f, -3.5}, Color{}};
Color c = c1.getColor();
Circle c2{8.5f, Vec2{-4.8f, 0.0f}, Color{0.0f, 1.0f, 0.0f}};

REQUIRE (c1.clr_.r_ == 0.0f);
REQUIRE (c1.clr_.g_ == 0.0f);
REQUIRE (c1.clr_.b_ == 0.0f);
REQUIRE (c2.getColor().r_ == 0.0f);
REQUIRE (c2.getColor().g_ == 1.0f);
REQUIRE (c2.getColor().b_ == 0.0f);
}

//Umfang
TEST_CASE (" circle_circumference ", "[circle_circumference]")
{

Circle c1{2.7f, Vec2{1.2f, -3.5}, Color{}};
float c = c1.circumference();
Circle c2{8.5f, Vec2{-4.8f, 0.0f}, Color{}};

REQUIRE (c == Approx(16.96460f));
REQUIRE (c2.circumference() == Approx(53.40707f));
}

//is_inside 
TEST_CASE (" circle_is_inside ", "[circle_is_inside]")
{

Circle c1{3.0f, Vec2{6.8f, 10.9}, Color{}};

bool i = c1.is_inside(Vec2{6.0f, 10.0f});

REQUIRE (i == true);
REQUIRE (c1.is_inside(Vec2{1.0f, 0.3f}) == false);
}



//Tests for rectangle
//Konstruktoren
TEST_CASE (" default_rectangle_Constr ", "[default_rectangle_Constr]")
{
Rectangle identRect{};

REQUIRE (identRect.min_.x_ == 0.0f);
REQUIRE (identRect.min_.y_ == 0.0f);
REQUIRE (identRect.max_.x_ == 1.0f);
REQUIRE (identRect.max_.y_ == 1.0f);
REQUIRE (identRect.clr_.r_ == 0.0f);
REQUIRE (identRect.clr_.g_ == 0.0f);
REQUIRE (identRect.clr_.b_ == 0.0f);
}

TEST_CASE (" rectangle_Constr ", "[rectangle_Constr]")
{
Rectangle rect{Vec2{2.2f, 3.4f}, Vec2{4.4f, 7.9f}, Color{}};

REQUIRE (rect.min_.x_ == 2.2f);
REQUIRE (rect.min_.y_ == 3.4f);
REQUIRE (rect.max_.x_ == 4.4f);
REQUIRE (rect.max_.y_ == 7.9f);
REQUIRE (rect.clr_.r_ == 0.0f);
REQUIRE (rect.clr_.g_ == 0.0f);
REQUIRE (rect.clr_.b_ == 0.0f);
}

//getter
TEST_CASE (" get_min ", "[get_min]")
{

Rectangle rect1{Vec2{2.2f, 3.4f}, Vec2{4.4f, 7.9f}, Color{1.0f, 0.0f,1.0f}};
Vec2 t = rect1.getMin();
Rectangle rect2{Vec2{0.0f, -3.4f}, Vec2{3.7f, 0.0f}, Color{}};

REQUIRE (t.x_ == 2.2f);
REQUIRE (t.y_ == 3.4f);
REQUIRE (rect2.getMin().x_ == 0.0f);
REQUIRE (rect2.getMin().y_ == -3.4f);
}

TEST_CASE (" get_max ", "[get_max]")
{

Rectangle rect1{Vec2{2.2f, 3.4f}, Vec2{4.4f, 7.9f}, Color{}};
Vec2 t = rect1.getMax();
Rectangle rect2{Vec2{0.0f, -3.4f}, Vec2{3.7f, 0.0f}, Color{}};

REQUIRE (t.x_ == 4.4f);
REQUIRE (t.y_ == 7.9f);
REQUIRE (rect2.getMax().x_ == 3.7f);
REQUIRE (rect2.getMax().y_ == 0.0f);
}

TEST_CASE (" get_Rect_Color ", "[get_Rect_Color]")
{

Rectangle r1{Vec2{2.2f, 3.4f}, Vec2{4.4f, 7.9f}, Color{}};
Color c = r1.getColor();
Rectangle r2{Vec2{0.0f, -3.4f}, Vec2{3.7f, 0.0f}, Color{0.0f,1.0f,0.0f}};

REQUIRE (r1.clr_.r_ == 0.0f);
REQUIRE (r1.clr_.g_ == 0.0f);
REQUIRE (r1.clr_.b_ == 0.0f);
REQUIRE (r2.getColor().r_ == 0.0f);
REQUIRE (r2.getColor().g_ == 1.0f);
REQUIRE (r2.getColor().b_ == 0.0f);
}

//Umfang
TEST_CASE (" rectangle_circumference ", "[rectangle_circumference]")
{

Rectangle rect1{Vec2{2.2f, 3.4f}, Vec2{4.4f, 7.9f}, Color{}};
float c = rect1.circumference();
Rectangle rect2{Vec2{0.0f, -3.4f}, Vec2{3.7f, 0.0f}, Color{}};

REQUIRE (c == 13.4f);
REQUIRE (rect2.circumference() == Approx(14.2f));
}

//is_inside 
TEST_CASE (" rectangle_is_inside ", "[rectangle_is_inside]")
{

Rectangle rect1{Vec2{2.2f, 10.7f}, Vec2{8.9f, 20.6f}, Color{}};

bool i = rect1.is_inside(Vec2{4.4f, 12.5f});

REQUIRE (i == true);
REQUIRE (rect1.is_inside(Vec2{1.0f, 0.3f}) == false);
}



int main(int argc, char *argv[]){


  return Catch::Session().run(argc, argv);
}
