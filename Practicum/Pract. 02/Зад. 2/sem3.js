// /** Example 1 */

// function Animal(name) {
//    this.name = name;
// }

// Animal.prototype.speak = function () {
//     console.log(this.name + " makes a noise.");
// };

// function Dog(name, breed) {
//    Animal.call(this, name);
//    this.breed = breed;
// }

// Dog.prototype = Object.create(Animal.prototype);

// Dog.prototype.bark = function () {
//    console.log(this.name + " barks!");
// };

//  var myDog = new Dog("Rex", "German Shepherd");
//  myDog.speak();
//  myDog.bark();

// /** Example 2 */

// function Animal(name) {
//    this.name = name;
// }

// const animal = new Animal("Fishy");
// Animal.prototype.speak = function () {
//    console.log(this.name + " makes a bubbling noise.");
// };

// var animal2 = new Animal("Birdy");
// animal2.speak = function () {
//    console.log(this.name + " makes an aeolian noise.");
// };

//  animal.speak();
//  animal2.speak();

// /** Example 3 */
// function Vehicle(make, model) {
//    this.make = make;
//    this.model = model;
// }

// Vehicle.prototype.start = function () {
//    console.log(this.make + " " + this.model + " is starting.");
// };

// function Car(make, model, doors) {
//    Vehicle.call(this, make, model);
//    this.doors = doors;
// }

// Car.prototype = new Vehicle();

//  Car.prototype.honk = function () {
//    console.log(this.make + " " + this.model + " honks!");
// };

// var myCar = new Car("Toyota", "Corolla", 4);
// myCar.start(); // Expected: "Toyota Corolla is starting."
// myCar.honk(); // Expected: "Toyota Corolla honks!"






// console.log("");
// // ЗАД 2

function Point(x, y) {
    this.x = x ;
    this.y = y;
}

Point.prototype.getDistance = function(point2) {
    return Math.sqrt((this.x - point2.x) * (this.x - point2.x) + (this.y - point2.y) * (this.y - point2.y));
}

var p1 = new Point(2, 4);
console.log(p1.getDistance(new Point(3, 3)));


// Зад 3
function Circle(x, y, r) {
    Point.call(this, x, y);
    this.r = r;
}

Circle.prototype.getCircumference = function() {
    return 2*Math.PI*this.r;
}

Circle.prototype.getArea = function() {
    return Math.PI*this.r*this.r;
}

var circle = new Circle(0, 0, 5);

console.log(circle.getCircumference());
console.log(circle.getArea());


// task 4

function Rectangle(x, y, a,b) {
    Point.call(this, x, y);
    this.a = a;
    this.b = b;
}

Rectangle.prototype.getPerimeter = function() {
    return 2*(this.a + this.b);
}

Rectangle.prototype.getArea = function() {
    return this.a*this.b;
}

Rectangle.prototype.getDiagonals = function() {
    var length = Math.sqrt(this.a*this.a + this.b*this.b);
    return [length, length];
}

var rect = new Rectangle(0, 0, 3, 4);
console.log(rect.getArea());
console.log(rect.getDiagonals());


function Prism(x,y,a,b,h) {
   // Rectangle.call(this, x,y,a,b);
    this.h = h;
}

var rect = new Rectangle(0,1,2,3);
Prism.prototype = Object.create(Rectangle.prototype);

Prism.prototype.getVolume = function() {
    return this.h * this.getArea();
}

var prism = new Prism(0,0,2,3,4);
console.log(prism.getVolume());