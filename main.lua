CurrentMatch = nil -- move to a main state handler later

local fighter = require("data.fighter")
local match = require("data.match")
local turn = require("combat.turn")

function love.load()
	math.randomseed(os.time())
	love.window.setTitle("Fighter's Road!")

	local fighter1 = fighter.create()
	local fighter2 = fighter.create()

	CurrentMatch = match.create(fighter1, fighter2)
end

-- TESTING

local function printMatchAction(match)
	print("Blue does " .. match.blueAction)
	print("while Red does " .. match.redAction)

	print("Blue Health: " .. match.blue.health .. " | " .. "Red Health: " .. match.red.health)
end

local timer = 0
function love.update(dt)
	timer = timer + dt
	if timer >= 1.5 then
		turn.resolve(CurrentMatch)
		printMatchAction(CurrentMatch)
		timer = 0
	end
end

function love.draw()
	love.graphics.circle("fill", 30, 30, 50)
end
