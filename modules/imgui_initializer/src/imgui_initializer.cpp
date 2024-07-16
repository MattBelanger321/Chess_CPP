#include <imgui_initializer.hpp>

#include <iostream>

namespace chess::display {

    imgui_initalizer::imgui_initalizer( std::string window_name ) :
        window( nullptr ), glsl_version( "#version 130" ), window_name( window_name )
    {
    }

    bool imgui_initalizer::init()
    {
        // Setup window
        glfwSetErrorCallback( error_callback );
        if ( !glfwInit() )
            return false;

        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#if __APPLE__
        glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );  // Required on Mac
#endif

        // Create window with graphics context
        window = glfwCreateWindow( 1280, 720, window_name.c_str(), NULL, NULL );
        if ( window == NULL )
            return false;
        glfwMakeContextCurrent( window );
        glfwSwapInterval( 1 );  // Enable vsync

        // Initialize GLEW
        if ( glewInit() != GLEW_OK ) {
            std::cerr << "Failed to initialize GLEW!" << std::endl;
            return false;
        }

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO & io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL( window, true );
        ImGui_ImplOpenGL3_Init( glsl_version );

        return true;
    }

    void imgui_initalizer::stop()
    {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        if ( window )
            glfwDestroyWindow( window );
        glfwTerminate();
    }

    void imgui_initalizer::main_loop( std::function< void() > & render_function )
    {
        while ( !glfwWindowShouldClose( window ) ) {
            // Poll and handle events (inputs, window resize, etc.)
            glfwPollEvents();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            render_function();

            // Rendering
            ImGui::Render();
            int imgui_initalizer_w, imgui_initalizer_h;
            glfwGetFramebufferSize( window, &imgui_initalizer_w, &imgui_initalizer_h );
            glViewport( 0, 0, imgui_initalizer_w, imgui_initalizer_h );
            glClearColor( 0.45f, 0.55f, 0.60f, 1.00f );
            glClear( GL_COLOR_BUFFER_BIT );
            ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

            // Update and Render additional Platform Windows
            ImGuiIO & io = ImGui::GetIO();

            glfwSwapBuffers( window );
        }
    }

    void imgui_initalizer::error_callback( int error, const char * description )
    {
        std::cerr << "Glfw Error " << error << ": " << description << std::endl;
    }

    void imgui_initalizer::run( std::function< void() > & render_function )
    {
        if ( !init() )
            return;
        main_loop( render_function );
    }

    imgui_initalizer::~imgui_initalizer() { stop(); }

}  // namespace chess::display