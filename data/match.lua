local match = {}

function match.create(fighter1, fighter2)
	local newMatch = {
		winner = nil,
		blueDistance = 0,
		redDistance = 0,
		turn = 0,
		blue = fighter1,
		red = fighter2,
		blueAction = "idle",
		redAction = "idle",
		rounds = {},
	}

	return newMatch
end

return match
