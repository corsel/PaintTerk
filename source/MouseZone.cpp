#include "MouseZone.h"

//MouseZone Class
MouseZone::MouseZone(Rectangle argZone)
	:zone(argZone) {}
Rectangle MouseZone::getZone() {return zone;}
void MouseZone::clickCallback(CoordinateInteger argCoordinate) {} //virtual

//RectangularMouseZone Class
RectangularMouseZone::RectangularMouseZone(Rectangle argZone, Widget *argBindedWidget)
	:MouseZone(argZone), bindedWidget(argBindedWidget) {}
void RectangularMouseZone::clickCallback(CoordinateInteger argCoordinate) //virtual implementation
{
	bindedWidget->clickCallback(argCoordinate);
}

//BufferMouseZone Class
BufferMouseZone::BufferMouseZone(Rectangle argZone, Buffer *argBindedBuffer)
	:MouseZone(argZone), bindedBuffer(argBindedBuffer)
{
	std::cout << "BufferMouseZone constructor bindedBuffer: " << bindedBuffer << std::endl;
	std::cout << "BufferMouseZone constructor argBindedBuffer: " << argBindedBuffer << std::endl;
}
void BufferMouseZone::clickCallback(CoordinateInteger argCoordinate) //virtual implementation
{
	if (Cursor::getInstance()->state == Cursor::CLICKED)
		bindedBuffer->paintPixel(argCoordinate, Color());
}

//ZoneContainer Class
ZoneContainer *ZoneContainer::instance = 0;
ZoneContainer::ZoneContainer() {}
ZoneContainer *ZoneContainer::getInstance()
{
	if (instance == 0)
		instance = new ZoneContainer();
	return instance;
}
void ZoneContainer::appendMouseZone(MouseZone *argZone)
{
	if (argZone != 0)
		zoneVector.push_back(argZone);
}
MouseZone *ZoneContainer::checkClick()
{
	//if (Cursor::getInstance()->state == Cursor::RELEASED) return 0;
	CoordinateInteger coord = Cursor::getInstance()->getScreenIntCoordinate();
	MouseZone *returnZone = 0;
	CoordinateFloat convertedCoordinate;
	convertedCoordinate.x = coord.x * 2.0f / screenWidth - 1.0f;
	convertedCoordinate.y = -coord.y * 2.0f / screenHeight + 1.0f;
   for (int i = 0; i < zoneVector.size(); i++)
   {
		if (zoneVector[i]->getZone().x1 <= convertedCoordinate.x &&
			zoneVector[i]->getZone().x2 >= convertedCoordinate.x &&
			zoneVector[i]->getZone().y1 <= convertedCoordinate.y &&
			zoneVector[i]->getZone().y2 >= convertedCoordinate.y)
		{
			returnZone = zoneVector[i];
		}
   }
   if (returnZone != 0) returnZone->clickCallback(coord);
   return returnZone;
}
