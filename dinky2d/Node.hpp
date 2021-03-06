//
//  Node.hpp
//  dinky2d
//
//  Created by Vincent Yao on 2017/7/16.
//  Copyright © 2017年 ookcode. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <string>
#include <vector>
#include "ProgramCache.hpp"
#include "Renderer.hpp"

namespace Dinky {
    
    class Node {
    public:
        Node();
        ~Node();
        
        void addChild(Node *node);
        std::vector<Node *> getChildren() {
            return _children;
        }
        
        void setParent(Node *node);
        Node* getParent() {
            return _parent;
        }
        
        void setSize(glm::vec2 size);
        glm::vec2& getSize() {
            return _size;
        }
        
        void setVisible(bool visible);
        bool getVisible() {
            return _visible;
        }
        
        void setPosition(glm::vec2 position);
        glm::vec2& getPosition() {
            return _position;
        }
        
        void setColor(glm::vec4 color);
        glm::vec4& getColor() {
            return _color;
        }
        
        void setRotation(float degrees);
        float getRotation() {
            return _rotation;
        }
        
        void setProgram(Program* program);
        Program* getProgram() {
            if(_program == nullptr) {
                return ProgramCache::getInstance()->getProgram(Program::SHADER_DEFAULT);
            }
            return _program;
        }
        
        void removeChild(Node *node);
        void removeFromParent();
        
        virtual void draw(Renderer* renderer, glm::mat4 &parentTransform);
        void visit(Renderer* renderer, glm::mat4 &parentTransform, bool isAncestor);
        
        glm::mat4& getParentToNodeTransform();
        glm::mat4& getModelViewTransform() {
            return _modelViewTransform;
        }
        
    private:
        std::vector<Node *> _children;
        bool _visible = true;
        Node *_parent = nullptr;
        Program* _program = nullptr;
        glm::vec4 _color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glm::vec2 _size = glm::vec2(0.0f, 0.0f);
        glm::vec2 _position = glm::vec2(0.0f, 0.0f);
        float _rotation = 0;
        glm::mat4 _modelViewTransform;
        glm::mat4 _transform;
    };
    
    
}

#endif /* Node_hpp */
