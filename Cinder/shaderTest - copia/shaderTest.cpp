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

class ImageFileTestApp : public AppBasic {
 public: 	
	void setup();
	void keyDown( KeyEvent event );
	
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


void ImageFileTestApp::setup()
{
	
		mTexture = gl::Texture::create( loadImage( "lachoy.png" ) );
	
	
		mShader = gl::GlslProg::create( loadResource( RES_PASSTHRU_VERT ), loadResource( RES_BLUR_FRAG ) );
	//mShader = gl::GlslProg( loadAsset( "vert.glsl"), loadAsset("frag.glsl") );
	
	
	
	mMaterial.setAmbient( Color::black() );
	mMaterial.setDiffuse( Color( 1.0f, 1.0f, 1.0f ) );

}

void ImageFileTestApp::keyDown( KeyEvent event )
{
	if( event.getCode() == app::KeyEvent::KEY_f ) {
		setFullScreen( ! isFullScreen() );
	}
}

void ImageFileTestApp::update()
{
	
	mRotation.x += 0.0f;
    mRotation.y += 1.0f;
	mLightPos.x = getMousePos().x;
	mLightPos.y = getMousePos().y;
	mLightPos.z = 200.0f;

}

void ImageFileTestApp::draw()
{
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
	gl::translate( Vec3f(300.0f, 140.0f, 180.0f ));
	gl::rotate(mRotation);
	gl::drawCylinder( 50.0f, 50.0f, 90.0f, 32, 32 );
	 gl::popMatrices();
	mTexture->unbind();
}


CINDER_APP_BASIC( ImageFileTestApp, RendererGl )