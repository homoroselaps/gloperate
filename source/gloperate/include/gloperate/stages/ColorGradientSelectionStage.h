#pragma once

#include <string>

#include <gloperate/pipeline/AbstractStage.h>
#include <gloperate/pipeline/InputSlot.h>
#include <gloperate/pipeline/Data.h>
#include <gloperate/base/ColorGradientList.h>

#include <gloperate/gloperate_api.h>


namespace gloperate
{

class AbstractColorGradient;

class GLOPERATE_API ColorGradientSelectionStage : public gloperate::AbstractStage
{
public:
    ColorGradientSelectionStage();
    virtual ~ColorGradientSelectionStage();

public:
    InputSlot<ColorGradientList> gradients;
    InputSlot<std::string> gradientName;

    Data<const AbstractColorGradient *> gradient;
    Data<size_t> gradientIndex;

protected:
    virtual void process() override;
};

} // namespace gloperate
