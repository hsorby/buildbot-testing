/*
Copyright 2015 University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.Some license of other
*/

#include "libcellml/model.h"

namespace libcellml {

Model::Model()
{

}

Model::~Model()
{

}

Model::Model(const Model& rhs)
    : ComponentEntity(rhs)
{

}

Model::Model(Model &&rhs)
    : ComponentEntity(std::move(rhs))
{

}

Model& Model::operator=(Model m)
{
    ComponentEntity::operator= (m);
    return *this;
}

std::string Model::doSerialisation(libcellml::CELLML_FORMATS format) const
{
    std::string repr = "";
    if (format == CELLML_FORMAT_XML) {
        repr += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<model xmlns=\"http://www.cellml.org/cellml/1.2#\"";
        if (getName().length()) {
            repr += " name=\"" + getName() + "\"";
        }
        repr += ">";
        for(size_t i = 0; i < componentCount(); i++) {
            repr += getComponent(i).serialise(format);
        }
        repr += "</model>";
    }

    return repr;
}

}
