#include "cinder/app/AppBasic.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Light.h"
#include "cinder/gl/Material.h"

#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// refs:
// creating projects: http://libcinder.org/docs/welcome/MSWNewProject.html
// programmable pipeline not yet supported: https://forum.libcinder.org/topic/opengl-4-1-best-practice-suggestion

class ImageFileTestApp : public AppBasic {
 public: 	
	void setup();
	
	void prepareSettings( Settings *settings );
	void update();
	void draw();
	
	gl::TextureRef	mTexture;	
	gl::GlslProgRef	mShader;
//	gl::GlslProg    mShader;
	float			mAngle;
	Vec3f			mRotation;
	gl::Material	mMaterial;
	Vec3f mLightPos;
};

void ImageFileTestApp::prepareSettings( Settings *settings ) {
  settings->setWindowSize(640, 360);
  settings->setFrameRate(60.0f);
  settings->setFullScreen(false);
}

void ImageFileTestApp::setup() {
  mTexture = gl::Texture::create( loadImage( "lachoy.png" ) );
  mShader = gl::GlslProg::create( loadResource( RES_PASSTHRU_VERT ), loadResource( RES_BLUR_FRAG ) );
	//mShader = gl::GlslProg( loadAsset( "vert.glsl"), loadAsset("frag.glsl") );
  mMaterial.setAmbient(Color::black());
  mMaterial.setDiffuse(Color( 1.0f, 1.0f, 1.0f ));
}

void ImageFileTestApp::update() {
	mRotation.x += 0.0f;
    mRotation.y += 1.0f;
	mLightPos.x = getMousePos().x;
	mLightPos.y = getMousePos().y;
	mLightPos.z = 200.0f;
}

void ImageFileTestApp::draw() {
  gl::clear();

  mTexture->enableAndBind();
	//glEnable( GL_TEXTURE_2D );
	
  gl::Light light( gl::Light::POINT, 0 );
  light.setPosition( mLightPos );
  light.setAttenuation( 1.0f, 0.0f, 0.0f );

  glEnable( GL_LIGHTING );
  light.enable();
  mMaterial.apply();

	//mShader.bind();
	//mShader.uniform( "tex0", 0 );
	//mShader.uniform( "lightPos", Vec3f(mLightPos));
  mShader->bind();
  mShader->uniform( "tex0", 0 );	
  mShader->uniform( "lightPos", Vec3f(mLightPos));
  gl::pushMatrices();
  gl::translate(Vec3f(getWindowWidth()/2.f, getWindowHeight()/2.0f + 100, 0.0f));
  gl::scale(1, -1, 1);
  gl::rotate(mRotation);
  gl::drawCylinder(100.0f, 100.0f, 200.0f, 32, 32);
  gl::popMatrices();
  mTexture->unbind();
}

CINDER_APP_BASIC( ImageFileTestApp, RendererGl )