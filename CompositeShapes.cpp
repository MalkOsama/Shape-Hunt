#include "CompositeShapes.h"
#include "gameConfig.h"
#include"fstream"
#define PII 3.14159265358979323846 


Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref), rotation_angle_sign(0)
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

void Sign::resizeUp(double factor)
{
    base->resizeUp(2);
    top->resizeUp(2);
}

void Sign::resizeDown(double factor)
{
    base->resizeDown(0.5);
    top->resizeDown(0.5);
}
void Sign::rotateclockwise90()
{
    base->rotateclockwise90();
    top->rotateclockwise90();

    point newTopRef = RefPoint;
    point newBaseRef;

    rotation_angle_sign += 90;
    rotation_angle_sign %= 360;  // Ensuring the angle stays within [0, 360)

    if (rotation_angle_sign == 90)
        newBaseRef = { RefPoint.x - config.sighShape.topWdth / 2 - config.sighShape.baseHeight / 2, RefPoint.y };
    else if (rotation_angle_sign == 180)
        newBaseRef = { RefPoint.x, RefPoint.y - config.sighShape.topWdth / 2 - config.sighShape.baseHeight / 2 };
    else if (rotation_angle_sign == 270)
        newBaseRef = { RefPoint.x + config.sighShape.topWdth / 2 + config.sighShape.baseHeight / 2, RefPoint.y };
    else
        newBaseRef = { RefPoint.x, RefPoint.y + config.sighShape.topWdth / 2 + config.sighShape.baseHeight / 2 };

    base->setRefPoint(newBaseRef);
    top->setRefPoint(newTopRef);
}

bool Sign::match(shape* sh) const
{
    Sign* sign = dynamic_cast<Sign*> (sh);
    if (sign) {
        return base->match(sign->base) && top->match(sign->top);
    }
    return false;
}

point Sign::getCenter() const
{
    return RefPoint;
}


Car::Car(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point wheel1Ref = { ref.x - config.carShape.bodyWidth / 2 + config.carShape.wheelRadius, ref.y + config.carShape.bodyHeight / 2 };
    point wheel2Ref = { ref.x + config.carShape.bodyWidth / 2 - config.carShape.wheelRadius, ref.y + config.carShape.bodyHeight / 2 };
    point bodyRef = { ref.x, ref.y };
    point roofRef = { ref.x, ref.y - config.carShape.bodyHeight / 2 };

    
    wheel1 = new circle(pGame, wheel1Ref, config.carShape.wheelRadius);
    wheel2 = new circle(pGame, wheel2Ref, config.carShape.wheelRadius);
    body = new Rect(pGame, bodyRef, config.carShape.bodyHeight, config.carShape.bodyWidth);
    roof = new triangle(pGame, roofRef, config.carShape.roofBase, config.carShape.roofHeight);
}

void Car::draw() const
{
    wheel1->draw();
    wheel2->draw();
    body->draw();
    roof->draw();
}

void Car::resizeUp(double factor)
{
    wheel1->resizeUp(2);
    wheel2->resizeUp(2);
    body->resizeUp(2);
    roof->resizeUp(2);
}

void Car::resizeDown(double factor)
{
    wheel1->resizeDown(0.5);
    wheel2->resizeDown(0.5);
    body->resizeDown(0.5);
    roof->resizeDown(0.5);
}
void Car::rotateclockwise90(){
    body->rotateclockwise90();
    roof->rotateclockwise90();
    wheel1->rotateclockwise90();
    wheel2->rotateclockwise90();

    point bodyRef = RefPoint;
    point roofRef;
    point wheel1Ref;
    point wheel2Ref;

    current_rotation_anggg += 90;
    current_rotation_anggg %= 360;

    if (current_rotation_anggg == 90) {
        roofRef = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.roofHeight / 2, RefPoint.y };
        wheel1Ref = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius, RefPoint.y - config.carShape.bodyWidth / 4 };
        wheel2Ref = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius, RefPoint.y + config.carShape.bodyWidth / 4 };
    }
    else if (current_rotation_anggg == 180) {
        roofRef = { RefPoint.x, RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.roofHeight / 2 };
        wheel1Ref = { RefPoint.x + config.carShape.bodyWidth / 4, RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius };
        wheel2Ref = { RefPoint.x - config.carShape.bodyWidth / 4, RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius };
    }
    else if (current_rotation_anggg == 270) {
        roofRef = { RefPoint.x - config.carShape.bodyWidth / 2 - config.carShape.roofHeight / 2, RefPoint.y };
        wheel1Ref = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius, RefPoint.y + config.carShape.bodyWidth / 4 };
        wheel2Ref = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius, RefPoint.y - config.carShape.bodyWidth / 4 };
    }
    else {
        roofRef = { RefPoint.x, RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.roofHeight / 2 };
        wheel1Ref = { RefPoint.x - config.carShape.bodyWidth / 4, RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
        wheel2Ref = { RefPoint.x + config.carShape.bodyWidth / 4, RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
    }

    body->setRefPoint(bodyRef);
    roof->setRefPoint(roofRef);
    wheel1->setRefPoint(wheel1Ref);
    wheel2->setRefPoint(wheel2Ref);
    
}
bool Car::match(shape* sh) const
{
    Car* car = dynamic_cast<Car*> (sh);
    if (car) {
        return body->match(car->body) && roof->match(car->roof) && wheel1->match(car->wheel1) && wheel2->match(car->wheel2);
    }
    return false;
}
point Car::getCenter() const
{
    return RefPoint;
}
void Car::Load(ifstream& Infile)
{
    int resized, rotated;
    Infile >> resized >> rotated;
    if (resized > 0)
    {
        for (int i = 0; i < resized; i++)
            this->resizeUp(1.5);
    }
    else if (resized < 0)
    {
        for (int i = 0; i > resized; i--)
            this->resizeDown(0.5);
    }
    if (rotated > 0)
    {
        for (int i = 0; i < rotated; i++)
            this->rotateclockwise90();
    }
}
House::House(game* r_pGame, point ref) : shape(r_pGame, ref),current_rotation_angg(0) {
    
    point baseRef = { ref.x, ref.y + config.houseShape.baseHeight / 2 };
    point doorRef = { ref.x - config.houseShape.baseWidth / 4, ref.y + config.houseShape.baseHeight / 4 };
    point roofRef = { ref.x, ref.y - config.houseShape.baseHeight / 2 };

   
    base = new Rect(pGame, baseRef, config.houseShape.baseHeight, config.houseShape.baseWidth);
    door = new Rect(pGame, doorRef, config.houseShape.doorHeight, config.houseShape.doorWidth);
    roof = new triangle(pGame, roofRef, config.houseShape.roofBase, config.houseShape.roofHeight);
}

void House::draw() const
{
    base->draw();
    door->draw();
    roof->draw();

}

void House::resizeUp(double factor)
{
    base->resizeUp(2);
    door->resizeUp(2);
    roof->resizeUp(2);
}

void House::resizeDown(double factor)
{
    base->resizeDown(0.5);
    door->resizeDown(0.5);
    roof->resizeDown(0.5);
}
void House::rotateclockwise90()
{
    base->rotateclockwise90();
    roof->rotateclockwise90();
    door->rotateclockwise90();

    current_rotation_angg += 90;
    current_rotation_angg %= 360;

    point newBaseRef = RefPoint;
    point newRoofRef;
    point newDoorRef;

    if (current_rotation_angg == 90) {
        newRoofRef = { RefPoint.x + config.houseShape.baseWidth / 2, RefPoint.y };
        newDoorRef = { RefPoint.x, RefPoint.y + config.houseShape.baseHeight / 4 };
    }
    else if (current_rotation_angg == 180) {
        newRoofRef = { RefPoint.x, RefPoint.y + config.houseShape.baseHeight / 2 };
        newDoorRef = { RefPoint.x - config.houseShape.baseWidth / 4, RefPoint.y };
    }
    else if (current_rotation_angg == 270) {
        newRoofRef = { RefPoint.x - config.houseShape.baseWidth / 2, RefPoint.y };
        newDoorRef = { RefPoint.x, RefPoint.y - config.houseShape.baseHeight / 4 };
    }
    else {
        newRoofRef = { RefPoint.x, RefPoint.y - config.houseShape.baseHeight / 2 };
        newDoorRef = { RefPoint.x + config.houseShape.baseWidth / 4, RefPoint.y };
    }

    base->setRefPoint(newBaseRef);
    roof->setRefPoint(newRoofRef);
    door->setRefPoint(newDoorRef);
}

bool House::match(shape* sh) const
{
    House* home = dynamic_cast<House*> (sh);
    if (home)
    {
        return base->match(home->base) && roof->match(home->roof) && door->match(home->door);
    }
    return false;
}

point House::getCenter() const
{
    return RefPoint;
}
void House::Load(ifstream& Infile)
{
    int resized, rotated;
    Infile >> resized >> rotated;
    if (resized > 0)
    {
        for (int i = 0; i < resized; i++)
            this->resizeUp(1.5);
    }
    else if (resized < 0)
    {
        for (int i = 0; i > resized; i--)
            this->resizeDown(0.5);
    }
    if (rotated > 0)
    {
        for (int i = 0; i < rotated; i++)
            this->rotateclockwise90();
    }
}
Tree::Tree(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point trunkRef = ref;
    point leavesRef1 = { ref.x, ref.y + config.treeShape.trunkHeight };
    point leavesRef2 = { ref.x, leavesRef1.y + config.treeShape.leavesHeight };

    trunk = new Rect(pGame, trunkRef, config.treeShape.trunkHeight, config.treeShape.trunkWidth);
    leaves1 = new triangle(pGame, leavesRef1, config.treeShape.leavesBase, config.treeShape.leavesHeight);
    leaves2 = new triangle(pGame, leavesRef2, config.treeShape.leavesBase, config.treeShape.leavesHeight);
}

void Tree::draw() const
{
    trunk->draw();
    leaves1->draw();
    leaves2->draw();
}

void Tree::resizeUp(double factor)
{
    trunk->resizeUp(2);
    leaves1->resizeUp(2);
    leaves2->resizeUp(2);
}

void Tree::resizeDown(double factor)
{
    trunk->resizeDown(0.5);
    leaves1->resizeDown(0.5);
    leaves2->resizeDown(0.5);
}
void Tree::rotateclockwise90() {
    trunk->rotateclockwise90();
    leaves1->rotateclockwise90();
    leaves2->rotateclockwise90();

    current_rotation_angle += 90;
    if (current_rotation_angle >= 360) current_rotation_angle = 0;

    point newTrunkRef = RefPoint;
    point newLeaves1Ref;
    point newLeaves2Ref;

    // Calculate new reference points based on the current rotation angle
    if (current_rotation_angle == 90) {
        newLeaves1Ref = { RefPoint.x + config.treeShape.trunkWidth / 2 + config.treeShape.leavesHeight / 2, RefPoint.y };
        newLeaves2Ref = { RefPoint.x - config.treeShape.trunkHeight / 2, RefPoint.y + config.treeShape.leavesBase / 2 };
    }
    else if (current_rotation_angle == 180) {
        newLeaves1Ref = { RefPoint.x, RefPoint.y + config.treeShape.trunkHeight / 2 + config.treeShape.leavesHeight / 2 };
        newLeaves2Ref = { RefPoint.x - config.treeShape.leavesBase / 2, RefPoint.y - config.treeShape.trunkWidth / 2 };
    }
    else if (current_rotation_angle == 270) {
        newLeaves1Ref = { RefPoint.x - config.treeShape.trunkWidth / 2 - config.treeShape.leavesHeight / 2, RefPoint.y };
        newLeaves2Ref = { RefPoint.x + config.treeShape.trunkHeight / 2, RefPoint.y - config.treeShape.leavesBase / 2 };
    }
    else {
        newLeaves1Ref = { RefPoint.x, RefPoint.y - config.treeShape.trunkHeight / 2 - config.treeShape.leavesHeight / 2 };
        newLeaves2Ref = { RefPoint.x + config.treeShape.leavesBase / 2, RefPoint.y + config.treeShape.trunkWidth / 2 };
    }

    trunk->setRefPoint(newTrunkRef);
    leaves1->setRefPoint(newLeaves1Ref);
    leaves2->setRefPoint(newLeaves2Ref);
}

bool Tree::match(shape* sh) const
{
    Tree* tree = dynamic_cast<Tree*>(sh);
    if (tree) {
        return trunk->match(tree->trunk) && leaves1->match(tree->leaves1) && leaves2->match(tree->leaves2);
    }
    return false;
}

point Tree::getCenter() const
{
    return RefPoint;
}
void Tree::Load(ifstream& Infile)
{
    int resized, rotated;
    Infile >> resized >> rotated;
    if (resized > 0)
    {
        for (int i = 0; i < resized; i++)
            this->resizeUp(1.5);
    }
    else if (resized < 0)
    {
        for (int i = 0; i > resized; i--)
            this->resizeDown(0.5);
    }
    if (rotated > 0)
    {
        for (int i = 0; i < rotated; i++)
            this->rotateclockwise90();
    }
}

Icecream::Icecream(game* r_pGame, point ref) : shape(r_pGame, ref), current_rotation_ang(180) {
    
    point scoopRef = ref;
    point coneRef = { ref.x, ref.y + config.icecreamShape.coneHeight / 2 };

    
    scoop = new circle(pGame, scoopRef, config.icecreamShape.scoopRadius);
    cone = new triangle(pGame, coneRef, config.icecreamShape.coneBase, config.icecreamShape.coneHeight);
}

void Icecream::draw() const
{
    scoop->draw();
    cone->draw();
}

void Icecream::resizeUp(double factor)
{
    scoop->resizeUp(2);
    cone->resizeUp(2);
}

void Icecream::resizeDown(double factor)
{
    scoop->resizeDown(0.5);
    cone->resizeDown(0.5);
}
void Icecream::rotateclockwise90() {
    scoop->rotateclockwise90();
    cone->rotateclockwise90();

    point NewScoopRef = RefPoint;
    point NewConeRef;

    current_rotation_ang += 90;
    double s = current_rotation_ang;
    if (s >= 270 && s < 360)
        NewConeRef = { RefPoint.x - config.icecreamShape.coneHeight / 2 ,RefPoint.y };
    else if (s >= 360)
    {
        NewConeRef = { RefPoint.x ,RefPoint.y - config.icecreamShape.coneHeight / 2 };
        current_rotation_ang = 0;
    }
    else if (s >= 90 && s < 180)
        NewConeRef = { RefPoint.x + config.icecreamShape.coneHeight / 2,RefPoint.y };
    else
        NewConeRef = { RefPoint.x ,RefPoint.y + config.icecreamShape.coneHeight / 2 };

    scoop->setRefPoint(NewScoopRef);
    cone->setRefPoint(NewConeRef);
}
bool Icecream::match(shape* sh) const
{
    Icecream* ice = dynamic_cast<Icecream*> (sh);
    if (ice) {
        return scoop->match(ice->scoop) && cone->match(ice->cone);
    }
    return false;
}
point Icecream::getCenter() const
{
    return RefPoint;
}
void Icecream::Load(ifstream& Infile)
{
    int resized, rotated;
    Infile >> resized >> rotated;
    if (resized > 0)
    {
        for (int i = 0; i < resized; i++)
            this->resizeUp(1.5);
    }
    else if (resized < 0)
    {
        for (int i = 0; i > resized; i--)
            this->resizeDown(0.5);
    }
    if (rotated > 0)
    {
        for (int i = 0; i < rotated; i++)
            this->rotateclockwise90();
    }
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
    ears = new triangle(pGame, earsRef, config.catShape.earBase, config.catShape.earHeight);
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

void Cat::resizeUp(double factor)
{
    head->resizeUp(2);
    ears->resizeUp(2);
    eyes[0]->resizeUp(2);
    eyes[1]->resizeUp(2);
    body->resizeUp(2);
    tail->resizeUp(2);
}

void Cat::resizeDown(double factor)
{
    head->resizeDown(0.5);
    ears->resizeDown(0.5);
    eyes[0]->resizeDown(0.5);
    eyes[1]->resizeDown(0.5);
    body->resizeDown(0.5);
    tail->resizeDown(0.5);
}
void Cat::rotateclockwise90() {
    head->rotateclockwise90();
    ears->rotateclockwise90();
    eyes[0]->rotateclockwise90();
    eyes[1]->rotateclockwise90();
    body->rotateclockwise90();
    tail->rotateclockwise90();

    current_rotation_angle += 90;
    if (current_rotation_angle >= 360) current_rotation_angle = 0;

    point newHeadRef = RefPoint;
    point newEarsRef;
    point newEyesRef[2];
    point newBodyRef;
    point newTailRef;

    // Calculate new reference points based on the current rotation angle
    if (current_rotation_angle == 90) {
        newEarsRef = { RefPoint.x, RefPoint.y + config.catShape.headRadius };
        newEyesRef[0] = { RefPoint.x - config.catShape.eyeDistance / 2, RefPoint.y + config.catShape.headRadius };
        newEyesRef[1] = { RefPoint.x + config.catShape.eyeDistance / 2, RefPoint.y + config.catShape.headRadius };
        newBodyRef = { RefPoint.x - config.catShape.headRadius, RefPoint.y };
        newTailRef = { RefPoint.x - config.catShape.headRadius - config.catShape.bodyWidth / 2, RefPoint.y + config.catShape.bodyLength };
    }
    else if (current_rotation_angle == 180) {
        newEarsRef = { RefPoint.x - config.catShape.headRadius, RefPoint.y };
        newEyesRef[0] = { RefPoint.x - config.catShape.headRadius, RefPoint.y - config.catShape.eyeDistance / 2 };
        newEyesRef[1] = { RefPoint.x - config.catShape.headRadius, RefPoint.y + config.catShape.eyeDistance / 2 };
        newBodyRef = { RefPoint.x, RefPoint.y - config.catShape.headRadius };
        newTailRef = { RefPoint.x + config.catShape.bodyWidth / 2, RefPoint.y - config.catShape.headRadius - config.catShape.bodyLength };
    }
    else if (current_rotation_angle == 270) {
        newEarsRef = { RefPoint.x, RefPoint.y - config.catShape.headRadius };
        newEyesRef[0] = { RefPoint.x - config.catShape.eyeDistance / 2, RefPoint.y - config.catShape.headRadius };
        newEyesRef[1] = { RefPoint.x + config.catShape.eyeDistance / 2, RefPoint.y - config.catShape.headRadius };
        newBodyRef = { RefPoint.x + config.catShape.headRadius, RefPoint.y };
        newTailRef = { RefPoint.x + config.catShape.headRadius + config.catShape.bodyWidth / 2, RefPoint.y - config.catShape.bodyLength };
    }
    else {
        newEarsRef = { RefPoint.x + config.catShape.headRadius, RefPoint.y };
        newEyesRef[0] = { RefPoint.x + config.catShape.headRadius, RefPoint.y - config.catShape.eyeDistance / 2 };
        newEyesRef[1] = { RefPoint.x + config.catShape.headRadius, RefPoint.y + config.catShape.eyeDistance / 2 };
        newBodyRef = { RefPoint.x, RefPoint.y + config.catShape.headRadius };
        newTailRef = { RefPoint.x - config.catShape.bodyWidth / 2, RefPoint.y + config.catShape.headRadius + config.catShape.bodyLength };
    }

    head->setRefPoint(newHeadRef);
    ears->setRefPoint(newEarsRef);
    eyes[0]->setRefPoint(newEyesRef[0]);
    eyes[1]->setRefPoint(newEyesRef[1]);
    body->setRefPoint(newBodyRef);
    tail->setRefPoint(newTailRef);
}

bool Cat::match(shape* sh) const
{
    Cat* cat = dynamic_cast<Cat*>(sh);
    if (cat) {
        return head->match(cat->head) && ears->match(cat->ears) &&
            eyes[0]->match(cat->eyes[0]) && eyes[1]->match(cat->eyes[1]) &&
            body->match(cat->body) && tail->match(cat->tail);
    }
    return false;
}

point Cat::getCenter() const
{
    return RefPoint;
}
void Cat::Load(ifstream& Infile)
{
    int resized, rotated;
    Infile >> resized >> rotated;
    if (resized > 0)
    {
        for (int i = 0; i < resized; i++)
            this->resizeUp(1.5);
    }
    else if (resized < 0)
    {
        for (int i = 0; i > resized; i--)
            this->resizeDown(0.5);
    }
    if (rotated > 0)
    {
        for (int i = 0; i < rotated; i++)
            this->rotateclockwise90();
    }
}