
#include <iostream>

#include <QApplication>
#include <QMainWindow>

#include <globjects/base/baselogging.h>

#include <gloperate/viewer/ViewerContext.h>
#include <gloperate/viewer/Surface.h>

#include <gloperate-qt/viewer/RenderWindow.h>
#include <gloperate-qt/viewer/Context.h>


using namespace gloperate;
using namespace gloperate_qt;


int main(int argc, char * argv[])
{
    // Initialize Qt application
    QApplication app(argc, argv);

    // Create viewer context
    ViewerContext viewerContext;

    // Create render window
    RenderWindow * window = new RenderWindow(&viewerContext);
    window->setContextFormat(window->surface()->negotiateContext());

    // Create main window
    QMainWindow mainWindow;
    mainWindow.setCentralWidget(QWidget::createWindowContainer(window));
    mainWindow.centralWidget()->setFocusPolicy(Qt::StrongFocus);
    mainWindow.show();

    // Initialize context, print context info
    window->context()->use();
    window->context()->setSwapInterval(Context::SwapInterval::VerticalSyncronization);
    /*
    globjects::info() << std::endl
        << "OpenGL Version:  " << window->context()->version() << std::endl
        << "OpenGL Vendor:   " << window->context()->vendor() << std::endl
        << "OpenGL Renderer: " << window->context()->renderer() << std::endl;
    */
    window->context()->release();

    // Run main loop
    return app.exec();
}