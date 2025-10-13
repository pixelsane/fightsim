local conditions = {}
local utils = require("combat.utils")

local function determineAttack(strategy)
	local rng = math.random(1, 3) -- Expand later for specials and based on strategy
	if rng == 1 then
		return "high_attack"
	elseif rng == 2 then
		return "mid_attack"
	elseif rng == 3 then
		return "low_attack"
	end
end

local function determineDefend(strategy)
	local rng = math.random(1, 3) -- Expand later for parries, dodges, and movements
	if rng == 1 then
		return "high_defend"
	elseif rng == 2 then
		return "mid_defend"
	elseif rng == 3 then
		return "low_defend"
	end
end

function conditions.determineAction(fighter, strategy)
	strategy = nil -- TBA

	local rng = math.random(1, 3)
	if rng == 1 then
		return determineAttack(strategy)
	elseif rng == 2 then
		return determineDefend(strategy)
	elseif rng == 3 then
		if utils.isSpecialAvailable(fighter) then -- and confirm strategy
			return "special"
		else
			return conditions.determineAction(fighter)
		end
	end
end

return conditions
