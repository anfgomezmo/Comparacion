Services.ResourceManager:addDirResource("Resources", false)

scene = Scene()

scene.ambientColor:setColor(0.2, 0.2, 0.2, 1.0)

box =  ScenePrimitive(ScenePrimitive.TYPE_CYLINDER, 2.5,1.3,30)
box:setMaterialByName("CubeMaterial")
box:setPosition(0.0, 0.5, 0.0)
scene:addEntity(box)

light = SceneLight(SceneLight.AREA_LIGHT, scene, 5)
scene:addLight(light)

scene:getDefaultCamera():setPosition(5,1,1)
scene:getDefaultCamera():lookAt(Vector3(0,0,0), Vector3(0,1,0))

lightPositionVal = 0

function Update(elapsed)
	lightPositionVal = lightPositionVal + elapsed
	light:setPosition(2+sin(lightPositionVal), 1+sin(lightPositionVal), 1)
end