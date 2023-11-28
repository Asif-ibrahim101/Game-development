// Week4.cpp: A program using the TL-Engine

#include "TL-Engine11.h" // TL-Engine11 include file and namespace
using namespace tle;

int main()
{
	// Create a 3D engine (using TL11 engine here) and open a window for it
	TLEngine* myEngine = New3DEngine(kTLX);
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder("Media");
	myEngine->AddMediaFolder("C:\\Users\\Public\\Documents\\TL-Engine11\\Media");

	/**** Set up your scene here ****/
	IMesh* floorMesh = myEngine->LoadMesh("Floor.x");
	IModel* floor = floorMesh->CreateModel();

	IMesh* cubeMesh = myEngine->LoadMesh("Cube.x");
	IModel* cube = cubeMesh->CreateModel(0, 5, 20);

	//state for the object
	int state = 0;

	//using vectors for the position
	float VectorX = 0.005f, VectorY = 0.010f, VectorZ = 0.0110f;

	ICamera* myCamera;
	myCamera = myEngine->CreateCamera(FPSCamera);

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		/**** Update your scene each frame here ****/

		//for moving any objects
		if (myEngine->KeyHeld(Key_L))
		{
			cube->MoveX(VectorX);
		}

		if (myEngine->KeyHeld(Key_J))
		{
			cube->MoveX(-VectorX);
		}

		if (myEngine->KeyHeld(Key_I))
		{
			cube->MoveZ(VectorZ);
		}

		if (myEngine->KeyHeld(Key_K))
		{
			cube->MoveZ(-VectorZ);
		}

		//for the object
		if (myEngine->KeyHit(Key_Space)) {
			if (state == 0)
			{
				cubeMesh->RemoveModel(cube);
				state = 1;
			}
			else
			{
				cube = cubeMesh->CreateModel(0, 5, 20);
				cube->SetSkin("006_tlxadd.tga");
				state = 0;
			}
		}

		// Stop if the Escape key is pressed
		if (myEngine->KeyHit(Key_Escape))
		{
			myEngine->Stop();
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}