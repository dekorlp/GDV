enum ViewOptions { perspective = 0, orthograpic = 1 };

class CameraManager
{
	private: 
		
		GLdouble cameraPositionX;
		GLdouble cameraPositionY;
		GLdouble cameraPositionZ;

		GLdouble viewAtPositionX;
		GLdouble viewAtPositionY;
		GLdouble viewAtPositionZ;

		GLfloat oldMousePositionX;
		GLfloat oldMousePositionY;

		GLuint viewPortWidth;
		GLuint viewPortheight;

		float pitch;
		float yaw;

		int viewOption; // viewOption
	public:
		CameraManager();
		CameraManager(ViewOptions options, GLuint viewPortWidth, GLuint viewPortheight);
		void reshapeDisplay(GLdouble nearPlane, GLdouble farPlane);
		void setCameraPosition(GLdouble cameraPositionX, GLdouble cameraPositionY, GLdouble cameraPositionZ);
		void setCameraLookAtPosition(GLdouble viewAtPositionX, GLdouble viewAtPositionY, GLdouble viewAtPositionZ);
		void setThirdPersonCamera(float mouseX, float mouseY);
		void repositionCamera();
		GLfloat getPitch();
		GLfloat getYaw();

};