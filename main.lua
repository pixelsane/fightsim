CurrentMatch = nil -- move to a main state handler later

local Fighter = require("data.fighter")
local Match = require("data.match")
local Turn = require("combat.turn")

function love.load()
	math.randomseed(os.time())
	love.window.setTitle("Fighter's Road!")
	love.graphics.setBackgroundColor(0.5, 0.5, 0.5)

	local fighter1 = Fighter.create()
	local fighter2 = Fighter.create()

	CurrentMatch = Match.create(fighter1, fighter2)
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
		Turn.resolve(CurrentMatch)
		printMatchAction(CurrentMatch)
		timer = 0
	end
end

function love.draw()
	local width = love.graphics.getWidth()
	local y = 400
	love.graphics.line(0, y, width, y)
end
