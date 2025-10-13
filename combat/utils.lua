local utils = {}

function utils.isSpecialAvailable(fighter)
	return fighter.focus >= fighter.specialCost -- TO BE REWORKED
end

function utils.isAttacking(action)
	return action == "high_attack" or action == "mid_attack" or action == "low_attack"
end

function utils.isDefending(action)
	return action == "high_defend" or action == "mid_defend" or action == "low_defend"
end

return utils
