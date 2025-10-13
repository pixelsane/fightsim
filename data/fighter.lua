local fighter = {}

fighter.baseHATK = 5
fighter.baseMATK = 3
fighter.baseLATK = 1

function fighter.create()
	local newFighter = {
		health = 100,
		focus = 50,
		speed = math.random(1, 5),
		strength = math.random(1, 5),
		defense = math.random(1, 5),
		specialCost = 100, -- TODO: multiple slotting rework
	}
	return newFighter
end

return fighter
