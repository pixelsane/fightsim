local utils = require("combat.utils")
local conditions = require("combat.conditions")
local fighter = require("data.fighter")

local turn = {}
local determineAction = conditions.determineAction

local function calculateDamage(defender, attacker, attackAction, defendAction)
	local blockModifier = 1
	if attackAction == "high_attack" then
		if defendAction == "high_defend" then
			blockModifier = fighter.baseHATK * attacker.strength
		elseif defendAction == "mid_defend" then
			blockModifier = 1.25
		end
		defender.health = defender.health - ((fighter.baseHATK * attacker.strength) / blockModifier)
	elseif attackAction == "mid_attack" then
		if defendAction == "high_defend" then
			blockModifier = 1.15
		elseif defendAction == "mid_defend" then
			blockModifier = fighter.baseMATK * attacker.strength
		elseif defendAction == "low_defend" then
			blockModifier = 1.15
		end
		defender.health = defender.health - ((fighter.baseMATK * attacker.strength) / blockModifier)
	elseif attackAction == "low_attack" then
		if defendAction == "mid_defend" then
			blockModifier = 1.25
		elseif defendAction == "low_defend" then
			blockModifier = fighter.baseMATK * attacker.strength
		end
		defender.health = defender.health - ((fighter.baseLATK * attacker.strength) / blockModifier)
	else
		error("Cannot determine Attack Action!")
	end
end

local function resolveDamage(match)
	local redAttacks = utils.isAttacking(match.redAction)
	local blueAttacks = utils.isAttacking(match.blueAction)
	-- local blueDefends = utils.isDefending(match.blueAction)
	local redFighter = match.red
	local blueFighter = match.blue

	if redAttacks then
		calculateDamage(blueFighter, redFighter, match.redAction, match.blueAction)
	end

	if blueAttacks then
		calculateDamage(redFighter, blueFighter, match.blueAction, match.blueAction)
	end
end

local function resolveActions(match)
	-- resolveCost(match)
	resolveDamage(match)
end

local function confirmWinningSide(match)
	local redIsKnockedOut = match.red.health <= 0
	local blueIsKnockedOut = match.blue.health <= 0

	if redIsKnockedOut and blueIsKnockedOut then
		match.winner = "draw"
	elseif blueIsKnockedOut then
		match.winner = "red"
	elseif redIsKnockedOut then
		match.winner = "blue"
	end
end

function turn.resolve(match)
	if match.winner ~= nil then
		return
	end

	-- Determine blueAction and redAction
	local blueFighter = match.blue
	local redFighter = match.red
	local blueAction = determineAction(blueFighter)
	local redAction = determineAction(redFighter)

	match.blueAction = blueAction
	match.redAction = redAction

	confirmWinningSide(match)
	resolveActions(match)
end

return turn
