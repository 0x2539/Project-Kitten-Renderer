#ifndef CAMERA_TEST_H
#define CAMERA_TEST_H

#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Camera.h"

using namespace CppUnit;
using namespace std;

class CameraTest : public CppUnit::TestFixture  {
private:

	CPPUNIT_TEST_SUITE(CameraTest);
	CPPUNIT_TEST(testTrue);
	CPPUNIT_TEST(testFalse);
	CPPUNIT_TEST_SUITE_END();
	
	Camera *camera;
	
public:
	//static CppUnit::TestSuite *suite();
	
  void setUp()
  {
	// create a new camera object
    camera = new Camera();
	// the camera position is centered to player
	// it's position becomes (110, 110) 
	// actually a rectangle (110, 110) (509, 509)
	camera -> init(300, 300, 20, 20, 400, 400);
  }

  void tearDown() 
  {
	// destroy camera object
    delete camera;
  }

  void testTrue()
  {
    CPPUNIT_ASSERT( camera -> isVisible(110, 110, 2, 2) == true );
    CPPUNIT_ASSERT( camera -> isVisible(110, 110, 400, 400) == true );
	CPPUNIT_ASSERT( camera -> isVisible(310, 310, 50, 100) == true );
	CPPUNIT_ASSERT( camera -> isVisible(350, 450, 30, 50) == true );
	
	CPPUNIT_ASSERT( camera -> isVisible(210, 310, 50, 60) == true );
    CPPUNIT_ASSERT( camera -> isVisible(440, 410, 40, 90) == true );
	CPPUNIT_ASSERT( camera -> isVisible(315, 315, 170, 180) == true );
	CPPUNIT_ASSERT( camera -> isVisible(111, 111, 399, 399) == true ); 
  }

  void testFalse()
  {
    CPPUNIT_ASSERT( camera -> isVisible(100, 100, 2, 2) == false );
    CPPUNIT_ASSERT( camera -> isVisible(0, 100, 2, 2) == false );
	CPPUNIT_ASSERT( camera -> isVisible(510, 510, 3, 3) == false );
	CPPUNIT_ASSERT( camera -> isVisible(515, 440, 20, 50) == false );
	  
	CPPUNIT_ASSERT( camera -> isVisible(0, 0, 109, 109) == false );
    CPPUNIT_ASSERT( camera -> isVisible(108, 108, 1, 1) == false );
	CPPUNIT_ASSERT( camera -> isVisible(50, 0, 59, 109) == false );
	CPPUNIT_ASSERT( camera -> isVisible(510, 510, 3, 3) == false );
  }
  
};

#endif