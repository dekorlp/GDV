class PolygonGenerator
{
private:
	GLfloat propellerRotationSpeed = 0.0f;
	GLuint hull;
	GLuint carbon;

	GLfloat oldMousePositionX;
	GLfloat oldMousePositionY;

	float pitch;
	float yaw;

public:
	void initPolygonGenerator();
	void createCockpit(GLfloat fSeitenL);
	void createPropeller(GLfloat fSeitenL);
	void createCube(GLfloat fSeitenL);
	void createSphere(GLfloat r, int lats, int longs);
	void createCylinder(GLfloat radius, GLfloat height);
	void createShip(GLfloat rotationSpeed);
};