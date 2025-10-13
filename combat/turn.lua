local utils = require("combat.utils")
local conditions = require("combat.conditions")
local fighter = require("data.fighter")

local turn = {}
local determineAction = conditions.determineAction

local function calculateDamage(fighter1, fighter2, attackType)
	if attackType == "high_attack" then
		fighter1.health = fighter1.health - (fighter.baseHATK * fighter2.strength)
	elseif attackType == "mid_attack" then
		fighter1.health = fighter1.health - (fighter.baseMATK * fighter2.strength)
	elseif attackType == "low_attack" then
		fighter1.health = fighter1.health - (fighter.baseLATK * fighter2.strength)
	else
		error("Cannot determine Attack Type!")
	end
end

local function resolveDamage(match)
	local redAttacks = utils.isAttacking(match.redAction)
	local blueAttacks = utils.isAttacking(match.blueAction)
	-- local blueDefends = utils.isDefending(match.blueAction)
	local redFighter = match.red
	local blueFighter = match.blue

	if redAttacks then
		calculateDamage(blueFighter, redFighter, match.redAction)
	end

	if blueAttacks then
		calculateDamage(redFighter, blueFighter, match.blueAction)
	end
end

local function resolveActions(match)
	-- resolveCost(match)
	resolveDamage(match)
end

function turn.resolve(match)
	-- Determine blueAction and redAction
	local blueFighter = match.blue
	local redFighter = match.red
	local blueAction = determineAction(blueFighter)
	local redAction = determineAction(redFighter)

	match.blueAction = blueAction
	match.redAction = redAction

	resolveActions(match)
end

return turn
