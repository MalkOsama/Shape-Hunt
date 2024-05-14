#include "CompositeShapes.h"
#include "gameConfig.h"


Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	
	point topRef = ref;	
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

void Sign::resizeUp()
{
    base->resizeUp();
    top->resizeUp();
}

void Sign::resizeDown()
{
    base->resizeDown();
    top->resizeDown();
}
void Sign::rotateclockwise90()
{
    base->rotateclockwise90();
    top->rotateclockwise90();
}


Car::Car(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point wheel1Ref = { ref.x - config.carShape.bodyWidth / 2 + config.carShape.wheelRadius, ref.y + config.carShape.bodyHeight / 2 };
    point wheel2Ref = { ref.x + config.carShape.bodyWidth / 2 - config.carShape.wheelRadius, ref.y + config.carShape.bodyHeight / 2 };
    point bodyRef = { ref.x, ref.y };
    point roofRef = { ref.x, ref.y - config.carShape.bodyHeight / 2 };

    
    wheel1 = new circle(pGame, wheel1Ref, config.carShape.wheelRadius);
    wheel2 = new circle(pGame, wheel2Ref, config.carShape.wheelRadius);
    body = new Rect(pGame, bodyRef, config.carShape.bodyHeight, config.carShape.bodyWidth);
    roof = new triangle(pGame, roofRef, config.carShape.roofBase, config.carShape.roofHeight, config.catShape.earHeight);
}

void Car::draw() const
{
    wheel1->draw();
    wheel2->draw();
    body->draw();
    roof->draw();
}

void Car::resizeUp()
{
    wheel1->resizeUp();
    wheel2->resizeUp();
    body->resizeUp();
    roof->resizeUp();
}

void Car::resizeDown()
{
    wheel1->resizeDown();
    wheel2->resizeDown();
    body->resizeDown();
    roof->resizeDown();
}
void Car::rotateclockwise90(){
    wheel1->rotateclockwise90();
    wheel2->rotateclockwise90();
    body->rotateclockwise90();
    roof->rotateclockwise90();
}
House::House(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point baseRef = { ref.x, ref.y + config.houseShape.baseHeight / 2 };
    point doorRef = { ref.x - config.houseShape.baseWidth / 4, ref.y + config.houseShape.baseHeight / 4 };
    point roofRef = { ref.x, ref.y - config.houseShape.baseHeight / 2 };

   
    base = new Rect(pGame, baseRef, config.houseShape.baseHeight, config.houseShape.baseWidth);
    door = new Rect(pGame, doorRef, config.houseShape.doorHeight, config.houseShape.doorWidth);
    roof = new triangle(pGame, roofRef, config.houseShape.roofBase, config.houseShape.roofHeight,config.catShape.earHeight);
}

void House::draw() const
{
    base->draw();
    door->draw();
    roof->draw();

}

void House::resizeUp()
{
    base->resizeUp();
    door->resizeUp();
    roof->resizeUp();
}

void House::resizeDown()
{
    base->resizeDown();
    door->resizeDown();
    roof->resizeDown();
}
void House::rotateclockwise90() {
    base->rotateclockwise90();
    door->rotateclockwise90();
    roof->rotateclockwise90();
}

Tree::Tree(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point trunkRef = ref;
    point leavesRef1 = { ref.x, ref.y + config.treeShape.trunkHeight };
    point leavesRef2 = { ref.x, leavesRef1.y + config.treeShape.leavesHeight };

    trunk = new Rect(pGame, trunkRef, config.treeShape.trunkHeight, config.treeShape.trunkWidth);
    leaves1 = new triangle(pGame, leavesRef1, config.treeShape.leavesBase, config.treeShape.leavesHeight, config.catShape.earHeight);
    leaves2 = new triangle(pGame, leavesRef2, config.treeShape.leavesBase, config.treeShape.leavesHeight,config.catShape.earHeight);
}

void Tree::draw() const
{
    trunk->draw();
    leaves1->draw();
    leaves2->draw();
}

void Tree::resizeUp()
{
    trunk->resizeUp();
    leaves1->resizeUp();
    leaves2->resizeUp();
}

void Tree::resizeDown()
{
    trunk->resizeDown();
    leaves1->resizeDown();
    leaves2->resizeDown();
}
void Tree::rotateclockwise90() {
    trunk->rotateclockwise90();
    leaves1->rotateclockwise90();
    leaves2->rotateclockwise90();
}


Icecream::Icecream(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point scoopRef = ref;
    point coneRef = { ref.x, ref.y + config.icecreamShape.coneHeight / 2 };

    
    scoop = new circle(pGame, scoopRef, config.icecreamShape.scoopRadius);
    cone = new triangle(pGame, coneRef, config.icecreamShape.coneBase, config.icecreamShape.coneHeight, config.icecreamShape.coneHeight);
}

void Icecream::draw() const
{
    scoop->draw();
    cone->draw();
}

void Icecream::resizeUp()
{
    scoop->resizeUp();
    cone->resizeUp();
}

void Icecream::resizeDown()
{
    scoop->resizeDown();
    cone->resizeDown();
}
void Icecream::rotateclockwise90() {
    scoop->rotateclockwise90();
    cone->rotateclockwise90();
}
Cat::Cat(game* r_pGame, point ref) : shape(r_pGame, ref) {
    // Calculate reference points for each component of the cat
    point headRef = ref;
    point earsRef = { ref.x, ref.y - config.catShape.headRadius };
    point eyesRef[2] = {
        { ref.x - config.catShape.eyeDistance / 2, ref.y },
        { ref.x + config.catShape.eyeDistance / 2, ref.y }
    };
    point bodyRef = { ref.x, ref.y + config.catShape.headRadius };
    point tailRef = { ref.x + config.catShape.bodyWidth / 2, ref.y + config.catShape.bodyLength };

    // Create the components of the cat
    head = new circle(pGame, headRef, config.catShape.headRadius);
    ears = new triangle(pGame, earsRef, config.catShape.earBase, config.catShape.earHeight, config.catShape.earHeight);
    eyes[0] = new circle(pGame, eyesRef[0], config.catShape.eyeRadius);
    eyes[1] = new circle(pGame, eyesRef[1], config.catShape.eyeRadius);
    body = new Rect(pGame, bodyRef, config.catShape.bodyLength, config.catShape.bodyWidth);
    tail = new Rect(pGame, tailRef, config.catShape.tailLength, config.catShape.tailWidth);
}

void Cat::draw() const
{
    head->draw();
    ears->draw();
    eyes[0]->draw();
    eyes[1]->draw();
    body->draw();
    tail->draw();
}

void Cat::resizeUp()
{
    head->resizeUp();
    ears->resizeUp();
    eyes[0]->resizeUp();
    eyes[1]->resizeUp();
    body->resizeUp();
    tail->resizeUp();
}

void Cat::resizeDown()
{
    head->resizeDown();
    ears->resizeDown();
    eyes[0]->resizeDown();
    eyes[1]->resizeDown();
    body->resizeDown();
    tail->resizeDown();
}
void Cat::rotateclockwise90() {
    head->rotateclockwise90();
    ears->rotateclockwise90();
    eyes[0]->rotateclockwise90();
    eyes[1]->rotateclockwise90();
    body->rotateclockwise90();
    tail->rotateclockwise90();
}