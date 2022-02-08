workspace "DoublePopsicle"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "DoublePopsicle"
    location "DoublePopsicle"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/third_party/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DP_PLATFORM_WIN",
            "DP_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/example")
        }

    filter "configurations:Debug"
        defines "DP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "DP_DIST"
        optimize "On"


    project "example"
        location "example"
        kind "ConsoleApp"
        language "C++"
    
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs
        {
            "DoublePopsicle/third_party/spdlog/include",
            "DoublePopsicle/src"
        }

        links
        {
            "DoublePopsicle"
        }
    
        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "DP_PLATFORM_WIN"
            }
    
        filter "configurations:Debug"
            defines "DP_DEBUG"
            symbols "On"
    
        filter "configurations:Release"
            defines "DP_RELEASE"
            optimize "On"
    
        filter "configurations:Dist"
            defines "DP_DIST"
            optimize "On"
    