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

local function printMatchAction(pmatch)
	print("Blue does " .. pmatch.blueAction)
	print("while Red does " .. pmatch.redAction)

	print("Blue Health: " .. pmatch.blue.health .. " | " .. "Red Health: " .. pmatch.red.health)
	if pmatch.winner ~= nil then
		print("Winner: " .. pmatch.winner)
	end
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
