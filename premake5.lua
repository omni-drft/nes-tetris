workspace "TetrisWorkspace"
    configurations { "Debug", "Release" }
    location(".")

project "Tetris"
    location "."
    kind "ConsoleApp"
    language "C++"
    targetdir "build/bin/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "src/**.cpp", "src/**.h" }

    includedirs { "dependencies/SFML/include" }
    libdirs { "dependencies/SFML/lib" }

    links { "opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "openal32.lib", "flac.lib", "vorbisenc.lib", "vorbisfile.lib", "vorbis.lib", "ogg.lib", "ws2_32.lib" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        architecture "x86_64"
        includedirs { "dependencies/SFML/include" }
        libdirs { "dependencies/SFML/lib" }
        links { "sfml-audio-s-d.lib", "sfml-graphics-s-d.lib", "sfml-network-s-d.lib", "sfml-system-s-d.lib", "sfml-window-s-d.lib" }
        defines { "GAME_PLATFORM_WINDOWS", "SFML_STATIC" }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        architecture "x86_64"
        includedirs { "dependencies/SFML/include" }
        libdirs { "dependencies/SFML/lib" }
        links { "sfml-audio-s.lib", "sfml-graphics-s.lib", "sfml-network-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }
        defines { "GAME_PLATFORM_WINDOWS", "SFML_STATIC" }