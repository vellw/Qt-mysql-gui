#ifndef SAVEWORKSPACE_HPP
#define SAVEWORKSPACE_HPP

#include <QString>
#include "save_workspace_global.hpp"

class SAVE_WORKSPACESHARED_EXPORT Saveworkspace
{

public:
    explicit Saveworkspace() = default;
protected:
    QString file_name;
};

#endif // SAVEWORKSPACE_HPP
