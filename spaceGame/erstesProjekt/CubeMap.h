class CubeMap
{
private:
	GLuint Back;
	GLuint Bottom;
	GLuint Front;
	GLuint Left;
	GLuint Right;
	GLuint Top;

	GLuint cubeMapList;

	float px, py, pz;
	GLfloat mWidth, mHeight, mLength;
public:
	void initCubeMap();
	void createVertizes(GLfloat fSeitenL);
	void drawCubeMap();
};