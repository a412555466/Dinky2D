//
//  Scene.cpp
//  dinky2d
//
//  Created by Vincent Yao on 2017/7/16.
//  Copyright © 2017年 ookcode. All rights reserved.
//

#include "Scene.hpp"

namespace Dinky {
    
    Scene::Scene() {
        
    }
    
    void Scene::render(Renderer *renderer) {
        visit(renderer, getParentToNodeTransform(), true);
    }
    
}
