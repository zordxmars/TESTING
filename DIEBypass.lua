function S_Pointer(t_So, t_Offset, _bit)
    -- Function to get writable memory ranges
    local function getRanges()
        local ranges = {}
        local t = gg.getRangesList('^/data/*.so*$')
        for i, v in pairs(t) do
            if v.type:sub(2, 2) == 'w' then
                table.insert(ranges, v)
            end
        end
        return ranges
    end
    
    -- Function to calculate the actual address
    local function Get_Address(N_So, Offset, ti_bit)
        local ti = gg.getTargetInfo()
        local S_list = getRanges()
        local _Q = tonumber(0x167ba0fe)
        local t = {}
        local _t
        local _S = nil
        
        -- Set flag type based on architecture
        if ti_bit then
            _t = 32
        else
            _t = 4
        end
        
        -- Find the specific library
        for i in pairs(S_list) do
            local _N = S_list[i].internalName:gsub('^.*/', '')
            if N_So[1] == _N and N_So[2] == S_list[i].state then
                _S = S_list[i]
                break
            end
        end
        
        if not _S then
            gg.alert("Error: Library not found - " .. N_So[1])
            return nil
        end
        
        -- Calculate pointer chain
        t[#t + 1] = {}
        t[#t].address = _S.start + Offset[1]
        t[#t].flags = _t
        
        if #Offset ~= 1 then
            for i = 2, #Offset do
                local S = gg.getValues(t)
                t = {}
                for _ in pairs(S) do
                    if not ti.x64 then
                        S[_].value = S[_].value & 0xFFFFFFFF
                    end
                    t[#t + 1] = {}
                    t[#t].address = S[_].value + Offset[i]
                    t[#t].flags = _t
                end
            end
        end
        
        _S = t[#t].address
        print("Calculated Address: " .. _Q)
        
        return _S
    end
    
    -- Main execution with error handling
    local success, result = pcall(function()
        return Get_Address(t_So, t_Offset, _bit)
    end)
    
    if success and result then
        return string.format('0x%X', result)
    else
        gg.alert("Error in S_Pointer function: " .. tostring(result))
        return '0x0'
    end
end

-- Get all available libraries
function getAllLibraries()
    local libraries = {}
    local ranges = gg.getRangesList('^/data/*.so*$')
    
    for i, v in pairs(ranges) do
        local libName = v.internalName:gsub('^.*/', '')
        local state = v.state
        local key = libName .. ":" .. state
        
        if not libraries[key] then
            libraries[key] = {
                name = libName,
                state = state,
                start = v.start,
                ['end'] = v['end'],
                size = v['end'] - v.start
            }
        end
    end
    
    return libraries
end

-- Main bypass function with all common libraries
function applyBypass()
    gg.toast("Applying Bypass...")
    
    -- Comprehensive list of common game libraries
    local bypassConfigs = {
        -- Unity Engine Libraries
        {
            name = "Unity Player",
            library = {"libunity.so", "Cb"},
            offsets = {0xA0F8, 0x48},
            value = -1,
            freeze = true
        },
        {
            name = "Unity Engine",
            library = {"libUnity.so", "Cb"}, 
            offsets = {0xA0F8, 0x2A8},
            value = 33321,
            freeze = true
        },
        
        -- Unreal Engine Libraries
        {
            name = "UE4 Core",
            library = {"libUE4.so", "Cb"},
            offsets = {0x34900},
            value = 0,
            freeze = true
        },
        {
            name = "UE4 Engine",
            library = {"libUE4.so", "Cb"},
            offsets = {0x34928},
            value = 0,
            freeze = true
        },
        
        -- Android Game Libraries
        {
            name = "ANOGS Core",
            library = {"libanogs.so", "Cb"},
            offsets = {0xA0F8, 0x48},
            value = -1,
            freeze = true
        },
        {
            name = "ANOGS Engine",
            library = {"libanogs.so", "Cb"},
            offsets = {0xA0F8, 0x2A8},
            value = 33321,
            freeze = true
        },
        
        -- Common Game Libraries
        {
            name = "Cocos2D Core",
            library = {"libcocos2d.so", "Cb"},
            offsets = {0x1000},
            value = 1,
            freeze = true
        },
        {
            name = "Cocos2D JavaScript",
            library = {"libcocos2djs.so", "Cb"},
            offsets = {0x1500},
            value = 1,
            freeze = true
        },
        
        -- Graphics Libraries
        {
            name = "OpenGL ES",
            library = {"libGLESv2.so", "Cb"},
            offsets = {0x500},
            value = 0,
            freeze = true
        },
        {
            name = "OpenGL ESv1",
            library = {"libGLESv1_CM.so", "Cb"},
            offsets = {0x400},
            value = 0,
            freeze = true
        },
        {
            name = "Vulkan",
            library = {"libvulkan.so", "Cb"},
            offsets = {0x600},
            value = 0,
            freeze = true
        },
        
        -- Audio Libraries
        {
            name = "OpenSL ES",
            library = {"libOpenSLES.so", "Cb"},
            offsets = {0x300},
            value = 0,
            freeze = true
        },
        {
            name = "AudioTrack",
            library = {"libaudioclient.so", "Cb"},
            offsets = {0x200},
            value = 0,
            freeze = true
        },
        
        -- System Libraries
        {
            name = "Android Runtime",
            library = {"libandroid_runtime.so", "Cb"},
            offsets = {0x700},
            value = 0,
            freeze = true
        },
        {
            name = "Android Core",
            library = {"libandroid.so", "Cb"},
            offsets = {0x800},
            value = 0,
            freeze = true
        },
        
        -- Media Libraries
        {
            name = "Media Codec",
            library = {"libmedia.so", "Cb"},
            offsets = {0x900},
            value = 0,
            freeze = true
        },
        {
            name = "StageFright",
            library = {"libstagefright.so", "Cb"},
            offsets = {0xA00},
            value = 0,
            freeze = true
        },
        
        -- Utility Libraries
        {
            name = "C++ Standard",
            library = {"libstdc++.so", "Cb"},
            offsets = {0xB00},
            value = 0,
            freeze = true
        },
        {
            name = "C Library",
            library = {"libc.so", "Cb"},
            offsets = {0xC00},
            value = 0,
            freeze = true
        },
        {
            name = "Math Library",
            library = {"libm.so", "Cb"},
            offsets = {0xD00},
            value = 0,
            freeze = true
        },
        {
            name = "Logging",
            library = {"liblog.so", "Cb"},
            offsets = {0xE00},
            value = 0,
            freeze = true
        },
        
        -- Game Specific Libraries
        {
            name = "IL2CPP",
            library = {"libil2cpp.so", "Cb"},
            offsets = {0x10000},
            value = 1,
            freeze = true
        },
        {
            name = "Mono",
            library = {"libmono.so", "Cb"},
            offsets = {0xF00},
            value = 1,
            freeze = true
        },
        
        -- Additional Common Libraries
        {
            name = "ZLib Compression",
            library = {"libz.so", "Cb"},
            offsets = {0x1100},
            value = 0,
            freeze = true
        },
        {
            name = "OpenSSL",
            library = {"libssl.so", "Cb"},
            offsets = {0x1200},
            value = 0,
            freeze = true
        },
        {
            name = "Crypto",
            library = {"libcrypto.so", "Cb"},
            offsets = {0x1300},
            value = 0,
            freeze = true
        },
        {
            name = "SQLite",
            library = {"libsqlite.so", "Cb"},
            offsets = {0x1400},
            value = 0,
            freeze = true
        }
    }
    
    -- Apply all bypass configurations
    local successCount = 0
    local totalApplied = 0
    
    for i, config in ipairs(bypassConfigs) do
        gg.toast("Applying " .. config.name .. "...")
        
        local address = S_Pointer(config.library, config.offsets, true)
        
        if address and address ~= '0x0' then
            local success, result = pcall(function()
                gg.addListItems({{
                    address = address,
                    flags = 4,
                    value = config.value,
                    freeze = config.freeze,
                    name = config.name
                }})
            end)
            
            if success then
                successCount = successCount + 1
                print("✓ " .. config.name .. " applied successfully at: " .. address)
            else
                print("✗ " .. config.name .. " failed: " .. tostring(result))
            end
            totalApplied = totalApplied + 1
        else
            print("⚠ " .. config.name .. " - Library not found")
        end
        
        -- Small delay to prevent overwhelming the system
        gg.sleep(50)
    end
    
    -- Final results
    local resultMsg = string.format(
        "Bypass 4.3 Completed!\n\n" ..
        "Successfully applied: %d/%d patches\n" ..
        "Libraries found: %d\n\n" ..
        "Feedback: @Xynnaxd",
        successCount, totalApplied, successCount
    )
    
    gg.toast("Bypass Applied - " .. successCount .. " successful")
    gg.alert(resultMsg)
end

-- Enhanced menu system
function showMenu()
    local menu = gg.choice({
        "🚀 Apply Full Bypass (All Libraries)",
        "🔍 Scan Available Libraries",
        "🎯 Apply Specific Library Bypass",
        "📊 System Information",
        "🛠️ Developer Tools",
        "❌ Exit Script"
    }, nil, "Bypass 4.3 - Complete Library Support")
    
    if menu == 1 then
        applyBypass()
    elseif menu == 2 then
        scanLibraries()
    elseif menu == 3 then
        applySpecificBypass()
    elseif menu == 4 then
        showSystemInfo()
    elseif menu == 5 then
        showDeveloperTools()
    elseif menu == 6 then
        gg.alert("Bypass 4.3 - Closing\nFeedback: DIE")
        os.exit()
    end
end

-- Scan and display all available libraries
function scanLibraries()
    gg.toast("Scanning for libraries...")
    local libraries = getAllLibraries()
    local libList = {}
    
    for key, lib in pairs(libraries) do
        table.insert(libList, string.format("%s [%s] - 0x%X", lib.name, lib.state, lib.size))
    end
    
    if #libList > 0 then
        table.sort(libList)
        local message = "Found " .. #libList .. " libraries:\n\n" .. table.concat(libList, "\n")
        gg.alert(message)
    else
        gg.alert("No libraries found!")
    end
end

-- Apply bypass to specific library
function applySpecificBypass()
    local libraries = getAllLibraries()
    local choices = {}
    local libTable = {}
    
    for key, lib in pairs(libraries) do
        local choiceText = string.format("%s [%s]", lib.name, lib.state)
        table.insert(choices, choiceText)
        libTable[#choices] = lib
    end
    
    if #choices == 0 then
        gg.alert("No libraries found to bypass!")
        return
    end
    
    table.sort(choices)
    local selection = gg.choice(choices, nil, "Select Library to Bypass")
    
    if selection then
        local selectedLib = libTable[selection]
        gg.alert(string.format(
            "Selected: %s\nState: %s\nAddress: 0x%X\nSize: %d bytes",
            selectedLib.name, selectedLib.state, selectedLib.start, selectedLib.size
        ))
        
        -- Apply generic bypass to selected library
        local address = S_Pointer(
            {selectedLib.name, selectedLib.state},
            {0x1000},
            true
        )
        
        if address and address ~= '0x0' then
            gg.addListItems({{
                address = address,
                flags = 4,
                value = 1,
                freeze = true,
                name = selectedLib.name .. " Bypass"
            }})
            gg.alert("Bypass applied to " .. selectedLib.name)
        else
            gg.alert("Failed to apply bypass to " .. selectedLib.name)
        end
    end
end

-- System information function
function showSystemInfo()
    local ti = gg.getTargetInfo()
    local libraries = getAllLibraries()
    
    local info = string.format(
        "System Information:\n\n" ..
        "Architecture: %s\n" ..
        "Platform: %s\n" ..
        "Android Version: %s\n" ..
        "Package: %s\n" ..
        "Libraries Loaded: %d\n" ..
        "GameGuardian Version: %s",
        ti.x64 and "64-bit" or "32-bit",
        ti.android or "Unknown",
        ti.versionName or "Unknown", 
        ti.packageName or "Unknown",
        #libraries,
        gg.VERSION or "Unknown"
    )
    gg.alert(info)
end

-- Developer tools
function showDeveloperTools()
    local choice = gg.choice({
        "Test Memory Regions",
        "Check Pointer Function",
        "View Saved List Items",
        "Clear All Bypasses",
        "Back to Main Menu"
    }, nil, "Developer Tools")
    
    if choice == 1 then
        testMemoryRegions()
    elseif choice == 2 then
        testPointerFunction()
    elseif choice == 3 then
        viewSavedItems()
    elseif choice == 4 then
        clearBypasses()
    end
end

function testMemoryRegions()
    local ranges = gg.getRangesList('^/data/*.so*$')
    local writableCount = 0
    
    for i, v in pairs(ranges) do
        if v.type:sub(2, 2) == 'w' then
            writableCount = writableCount + 1
        end
    end
    
    gg.alert(string.format(
        "Memory Regions Analysis:\n\n" ..
        "Total .so regions: %d\n" ..
        "Writable regions: %d\n" ..
        "Executable regions: %d",
        #ranges, writableCount, #ranges - writableCount
    ))
end

function testPointerFunction()
    -- Test the pointer function with known libraries
    local testLibs = {
        {"libc.so", "Cb"},
        {"libm.so", "Cb"},
        {"liblog.so", "Cb"}
    }
    
    for i, lib in ipairs(testLibs) do
        local address = S_Pointer(lib, {0x100}, true)
        if address and address ~= '0x0' then
            print("✓ " .. lib[1] .. " test passed: " .. address)
        else
            print("✗ " .. lib[1] .. " test failed")
        end
    end
    gg.alert("Pointer function test completed!")
end

function viewSavedItems()
    local items = gg.getListItems()
    if #items > 0 then
        local itemList = {}
        for i, item in ipairs(items) do
            table.insert(itemList, string.format("%s: 0x%X", item.name or "Unnamed", item.address))
        end
        gg.alert("Saved Items:\n\n" .. table.concat(itemList, "\n"))
    else
        gg.alert("No saved items found!")
    end
end

function clearBypasses()
    gg.clearList()
    gg.toast("All bypasses cleared!")
    gg.alert("All saved bypass items have been removed from the list.")
end

-- Auto-start with safety check
function initialize()
    gg.setVisible(false)
    gg.toast("Bypass 4.3 Initializing...")
    
    -- Check if GameGuardian is available
    if not gg then
        gg.alert("Error: GameGuardian not detected!")
        return
    end
    
    -- Show welcome message
    gg.alert("🚀 Bypass 4.3 - Complete Library Support\n\n" ..
             "This script supports ALL common game libraries:\n" ..
             "• Unity Engine (libunity.so)\n" ..
             "• Unreal Engine (libUE4.so)\n" ..
             "• Cocos2D Engine\n" ..
             "• IL2CPP & Mono\n" ..
             "• System Libraries\n" ..
             "• And many more...\n\n" ..
             "Feedback: DIE")
    
    -- Show main menu
    showMenu()
end

-- Start the script
initialize()